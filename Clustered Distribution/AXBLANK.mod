TITLE Sensory Axon Internodal channels

: originally written 11/11/2017
: last update 12/1/2017
: Nabeel Chowdhury
:
: The channel equations come mainly from Ali Neishabouri and Jenny Tigerholm to simulate a C fiber
: Code originally derived form the MRG model

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	SUFFIX axblank
	NONSPECIFIC_CURRENT ikdr
	NONSPECIFIC_CURRENT il
	RANGE gkdrbar, gl, ek
	RANGE ndr_inf
	RANGE tau_ndr
}


UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {

	gkdrbar   = .00017	(mho/cm2)
	gl = .00014	(mho/cm2)
	ek      = -85	(mV)
	el		= -61.14	(mV)
	dt	(ms)
	v	(mV)
}

STATE {
	ndr
}

ASSIGNED {
	ikdr	(mA/cm2)
	il	(mA/cm2)
	ndr_inf
	tau_ndr
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ikdr = .05*gkdrbar * ndr*ndr*ndr*ndr * (v-ek) :reduced to make the hyperpolarization between nodes smaller.
	il = gl * (v-el)
}

DERIVATIVE states {   : exact Hodgkin-Huxley equations
       evaluate_fct(v)
	ndr' = (ndr_inf - ndr)/tau_ndr
}

UNITSOFF

INITIAL {

	evaluate_fct(v)
	ndr = ndr_inf
}

PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b
	
	if (v == 72.2) {
		v = 72.201
		}else if (v == -55){
		v = -55.01
	}
	a = 0.00798*(v+72.2)/(1-Exp((-72.2-v)/1.1))
	b = 0.0142*(-55-v)/(1-Exp((v+55)/10.5))
	tau_ndr = 1 / (a + b)
	ndr_inf = a / (a + b)
}

FUNCTION Exp(x) {
	if (x < -100) {
		Exp = 0
	}else{
		Exp = exp(x)
	}
}

UNITSON
