TITLE Saltatory Sensory Axon Node channels

: originally written 11/11/2017
: last update 12/1/2017
: Nabeel Chowdhury
:
: The channel equations come mainly from Ali Neishabouri and Jenny Tigerholm to simulate a C fiber
: Code originally derived form the MRG model

INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	SUFFIX saxnode
	NONSPECIFIC_CURRENT ina1_7
	NONSPECIFIC_CURRENT ina1_8
	NONSPECIFIC_CURRENT ikdr
	NONSPECIFIC_CURRENT il
	RANGE gna1_7bar, gna1_8bar, gkdrbar, gl, ena, ek
	RANGE m1_7_inf, h1_7_inf, s1_7_inf, m1_8_inf, h1_8_inf, ndr_inf
	RANGE tau_m1_7, tau_h1_7, tau_s1_7, tau_m1_8, tau_h1_8, tau_ndr
}


UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
}

PARAMETER {

	gna1_7bar	= .1066439	(mho/cm2)
	gna1_8bar	= .00125	(mho/cm2)
	gkdrbar   = .00017	(mho/cm2)
	gl = .00014	(mho/cm2)
	ena     = 79.6	(mV)
	ek      = -85	(mV)
	el		= -61.14	(mV)
	dt	(ms)
	v	(mV)
}

STATE {
	m1_7 h1_7 s1_7 m1_8 h1_8 ndr
}

ASSIGNED {
	ina1_7	(mA/cm2)
	ina1_8	(mA/cm2)
	ikdr	(mA/cm2)
	il	(mA/cm2)
	m1_7_inf
	h1_7_inf
	s1_7_inf
	m1_8_inf
	h1_8_inf
	ndr_inf
	tau_m1_7
	tau_h1_7
	tau_s1_7
	tau_m1_8
	tau_h1_8
	tau_ndr
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	ina1_7 = gna1_7bar * m1_7*m1_7*m1_7*h1_7*s1_7 * (v-ena)
	ina1_8 = 20*gna1_8bar * m1_8*m1_8*m1_8*h1_8 * (v-ena) :multiplied to a much higher than normal value to make saltatory conduction happen
	ikdr = 20*gkdrbar * ndr*ndr*ndr*ndr * (v-ek) :multiplid to compensate for the above gain
	il = gl * (v-el)
}

DERIVATIVE states {   : exact Hodgkin-Huxley equations
       evaluate_fct(v)
	m1_7' = (m1_7_inf - m1_7)/tau_m1_7
	h1_7' = (h1_7_inf - h1_7)/tau_h1_7
	s1_7' = (s1_7_inf - s1_7)/tau_s1_7
	m1_8' = (m1_8_inf - m1_8)/tau_m1_8
	h1_8' = (h1_8_inf - h1_8)/tau_h1_8
	ndr' = (ndr_inf - ndr)/tau_ndr
}

UNITSOFF

INITIAL {

	evaluate_fct(v)
	m1_7 = m1_7_inf
	h1_7 = h1_7_inf
	s1_7 = s1_7_inf
	m1_8 = m1_8_inf
	h1_8 = h1_8_inf
	ndr = ndr_inf
}

PROCEDURE evaluate_fct(v(mV)) { LOCAL a,b

	a = 15.5/(1+Exp((v-5)/(-12.08)))
	b = 35.2/(1+Exp((v+72.7)/16.7))
	tau_m1_7 = 1 / (a + b)/2.5
	m1_7_inf = a / (a + b)
	
	a = 0.38685/(1+Exp((v+122.35)/15.29))
	b = -0.00283+2.00283/(1+Exp((v+5.5266)/(-12.70195)))
	tau_h1_7 = 1 / (a + b)/2.5
	h1_7_inf = a / (a + b)
	
	a = 0.00003+0.00092/(1+Exp((v+93.9)/16.6))
	b = 132.05-132.05/(1+Exp((v+384.9)/28.5))
	tau_s1_7 = 1 / (a + b)/2.5
	s1_7_inf = a / (a + b)

	a = 3.83/(1+Exp((v+2.58)/-11.47))
	b = 6.894/(1+Exp((v+61.2)/19.8))
	tau_m1_8 = 1 / (a + b)
	m1_8_inf = a / (a + b)
	
	a = 0.013536*Exp(-(v+105)/46.33)
	b = 0.61714/(1+Exp((v-21.8)/-11.998))
	tau_h1_8 = 1 / (a + b)
	h1_8_inf = a / (a + b)
	
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
