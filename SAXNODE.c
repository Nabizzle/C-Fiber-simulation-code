/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__saxnode
#define _nrn_initial _nrn_initial__saxnode
#define nrn_cur _nrn_cur__saxnode
#define _nrn_current _nrn_current__saxnode
#define nrn_jacob _nrn_jacob__saxnode
#define nrn_state _nrn_state__saxnode
#define _net_receive _net_receive__saxnode 
#define evaluate_fct evaluate_fct__saxnode 
#define states states__saxnode 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gna1_7bar _p[0]
#define gna1_8bar _p[1]
#define gkdrbar _p[2]
#define gl _p[3]
#define ena _p[4]
#define ek _p[5]
#define ina1_7 _p[6]
#define ina1_8 _p[7]
#define ikdr _p[8]
#define il _p[9]
#define m1_7_inf _p[10]
#define h1_7_inf _p[11]
#define s1_7_inf _p[12]
#define m1_8_inf _p[13]
#define h1_8_inf _p[14]
#define ndr_inf _p[15]
#define tau_m1_7 _p[16]
#define tau_h1_7 _p[17]
#define tau_s1_7 _p[18]
#define tau_m1_8 _p[19]
#define tau_h1_8 _p[20]
#define tau_ndr _p[21]
#define m1_7 _p[22]
#define h1_7 _p[23]
#define s1_7 _p[24]
#define m1_8 _p[25]
#define h1_8 _p[26]
#define ndr _p[27]
#define Dm1_7 _p[28]
#define Dh1_7 _p[29]
#define Ds1_7 _p[30]
#define Dm1_8 _p[31]
#define Dh1_8 _p[32]
#define Dndr _p[33]
#define v _p[34]
#define _g _p[35]
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_Exp(void);
 static void _hoc_evaluate_fct(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_saxnode", _hoc_setdata,
 "Exp_saxnode", _hoc_Exp,
 "evaluate_fct_saxnode", _hoc_evaluate_fct,
 0, 0
};
#define Exp Exp_saxnode
 extern double Exp( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define el el_saxnode
 double el = -61.14;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "el_saxnode", "mV",
 "gna1_7bar_saxnode", "mho/cm2",
 "gna1_8bar_saxnode", "mho/cm2",
 "gkdrbar_saxnode", "mho/cm2",
 "gl_saxnode", "mho/cm2",
 "ena_saxnode", "mV",
 "ek_saxnode", "mV",
 "ina1_7_saxnode", "mA/cm2",
 "ina1_8_saxnode", "mA/cm2",
 "ikdr_saxnode", "mA/cm2",
 "il_saxnode", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double h1_80 = 0;
 static double h1_70 = 0;
 static double m1_80 = 0;
 static double m1_70 = 0;
 static double ndr0 = 0;
 static double s1_70 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "el_saxnode", &el_saxnode,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[0]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"saxnode",
 "gna1_7bar_saxnode",
 "gna1_8bar_saxnode",
 "gkdrbar_saxnode",
 "gl_saxnode",
 "ena_saxnode",
 "ek_saxnode",
 0,
 "ina1_7_saxnode",
 "ina1_8_saxnode",
 "ikdr_saxnode",
 "il_saxnode",
 "m1_7_inf_saxnode",
 "h1_7_inf_saxnode",
 "s1_7_inf_saxnode",
 "m1_8_inf_saxnode",
 "h1_8_inf_saxnode",
 "ndr_inf_saxnode",
 "tau_m1_7_saxnode",
 "tau_h1_7_saxnode",
 "tau_s1_7_saxnode",
 "tau_m1_8_saxnode",
 "tau_h1_8_saxnode",
 "tau_ndr_saxnode",
 0,
 "m1_7_saxnode",
 "h1_7_saxnode",
 "s1_7_saxnode",
 "m1_8_saxnode",
 "h1_8_saxnode",
 "ndr_saxnode",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 36, _prop);
 	/*initialize range parameters*/
 	gna1_7bar = 0.106644;
 	gna1_8bar = 0.00125;
 	gkdrbar = 0.00017;
 	gl = 0.00014;
 	ena = 79.6;
 	ek = -85;
 	_prop->param = _p;
 	_prop->param_size = 36;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _SAXNODE_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_prop_size(_mechtype, 36, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 saxnode C:/Users/padaw_000/Documents/Class/Bio Electric Phenomina/Final Project/Project Model/SAXNODE.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Saltatory Sensory Axon Node channels";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[6], _dlist1[6];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   evaluate_fct ( _threadargscomma_ v ) ;
   Dm1_7 = ( m1_7_inf - m1_7 ) / tau_m1_7 ;
   Dh1_7 = ( h1_7_inf - h1_7 ) / tau_h1_7 ;
   Ds1_7 = ( s1_7_inf - s1_7 ) / tau_s1_7 ;
   Dm1_8 = ( m1_8_inf - m1_8 ) / tau_m1_8 ;
   Dh1_8 = ( h1_8_inf - h1_8 ) / tau_h1_8 ;
   Dndr = ( ndr_inf - ndr ) / tau_ndr ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 evaluate_fct ( _threadargscomma_ v ) ;
 Dm1_7 = Dm1_7  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m1_7 )) ;
 Dh1_7 = Dh1_7  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_h1_7 )) ;
 Ds1_7 = Ds1_7  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s1_7 )) ;
 Dm1_8 = Dm1_8  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m1_8 )) ;
 Dh1_8 = Dh1_8  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_h1_8 )) ;
 Dndr = Dndr  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_ndr )) ;
 return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   evaluate_fct ( _threadargscomma_ v ) ;
    m1_7 = m1_7 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_m1_7)))*(- ( ( ( m1_7_inf ) ) / tau_m1_7 ) / ( ( ( ( - 1.0 ) ) ) / tau_m1_7 ) - m1_7) ;
    h1_7 = h1_7 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_h1_7)))*(- ( ( ( h1_7_inf ) ) / tau_h1_7 ) / ( ( ( ( - 1.0 ) ) ) / tau_h1_7 ) - h1_7) ;
    s1_7 = s1_7 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_s1_7)))*(- ( ( ( s1_7_inf ) ) / tau_s1_7 ) / ( ( ( ( - 1.0 ) ) ) / tau_s1_7 ) - s1_7) ;
    m1_8 = m1_8 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_m1_8)))*(- ( ( ( m1_8_inf ) ) / tau_m1_8 ) / ( ( ( ( - 1.0 ) ) ) / tau_m1_8 ) - m1_8) ;
    h1_8 = h1_8 + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_h1_8)))*(- ( ( ( h1_8_inf ) ) / tau_h1_8 ) / ( ( ( ( - 1.0 ) ) ) / tau_h1_8 ) - h1_8) ;
    ndr = ndr + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_ndr)))*(- ( ( ( ndr_inf ) ) / tau_ndr ) / ( ( ( ( - 1.0 ) ) ) / tau_ndr ) - ndr) ;
   }
  return 0;
}
 
static int  evaluate_fct ( _threadargsprotocomma_ double _lv ) {
   double _la , _lb ;
 _la = 15.5 / ( 1.0 + Exp ( _threadargscomma_ ( _lv - 5.0 ) / ( - 12.08 ) ) ) ;
   _lb = 35.2 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 72.7 ) / 16.7 ) ) ;
   tau_m1_7 = 1.0 / ( _la + _lb ) / 2.5 ;
   m1_7_inf = _la / ( _la + _lb ) ;
   _la = 0.38685 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 122.35 ) / 15.29 ) ) ;
   _lb = - 0.00283 + 2.00283 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 5.5266 ) / ( - 12.70195 ) ) ) ;
   tau_h1_7 = 1.0 / ( _la + _lb ) / 2.5 ;
   h1_7_inf = _la / ( _la + _lb ) ;
   _la = 0.00003 + 0.00092 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 93.9 ) / 16.6 ) ) ;
   _lb = 132.05 - 132.05 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 384.9 ) / 28.5 ) ) ;
   tau_s1_7 = 1.0 / ( _la + _lb ) / 2.5 ;
   s1_7_inf = _la / ( _la + _lb ) ;
   _la = 3.83 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 2.58 ) / - 11.47 ) ) ;
   _lb = 6.894 / ( 1.0 + Exp ( _threadargscomma_ ( _lv + 61.2 ) / 19.8 ) ) ;
   tau_m1_8 = 1.0 / ( _la + _lb ) ;
   m1_8_inf = _la / ( _la + _lb ) ;
   _la = 0.013536 * Exp ( _threadargscomma_ - ( _lv + 105.0 ) / 46.33 ) ;
   _lb = 0.61714 / ( 1.0 + Exp ( _threadargscomma_ ( _lv - 21.8 ) / - 11.998 ) ) ;
   tau_h1_8 = 1.0 / ( _la + _lb ) ;
   h1_8_inf = _la / ( _la + _lb ) ;
   if ( _lv  == 72.2 ) {
     _lv = 72.201 ;
     }
   else if ( _lv  == - 55.0 ) {
     _lv = - 55.01 ;
     }
   _la = 0.00798 * ( _lv + 72.2 ) / ( 1.0 - Exp ( _threadargscomma_ ( - 72.2 - _lv ) / 1.1 ) ) ;
   _lb = 0.0142 * ( - 55.0 - _lv ) / ( 1.0 - Exp ( _threadargscomma_ ( _lv + 55.0 ) / 10.5 ) ) ;
   tau_ndr = 1.0 / ( _la + _lb ) ;
   ndr_inf = _la / ( _la + _lb ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 evaluate_fct ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double Exp ( _threadargsprotocomma_ double _lx ) {
   double _lExp;
 if ( _lx < - 100.0 ) {
     _lExp = 0.0 ;
     }
   else {
     _lExp = exp ( _lx ) ;
     }
   
return _lExp;
 }
 
static void _hoc_Exp(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  Exp ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 6;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h1_8 = h1_80;
  h1_7 = h1_70;
  m1_8 = m1_80;
  m1_7 = m1_70;
  ndr = ndr0;
  s1_7 = s1_70;
 {
   evaluate_fct ( _threadargscomma_ v ) ;
   m1_7 = m1_7_inf ;
   h1_7 = h1_7_inf ;
   s1_7 = s1_7_inf ;
   m1_8 = m1_8_inf ;
   h1_8 = h1_8_inf ;
   ndr = ndr_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   ina1_7 = gna1_7bar * m1_7 * m1_7 * m1_7 * h1_7 * s1_7 * ( v - ena ) ;
   ina1_8 = 20.0 * gna1_8bar * m1_8 * m1_8 * m1_8 * h1_8 * ( v - ena ) ;
   ikdr = 20.0 * gkdrbar * ndr * ndr * ndr * ndr * ( v - ek ) ;
   il = gl * ( v - el ) ;
   }
 _current += ina1_7;
 _current += ina1_8;
 _current += ikdr;
 _current += il;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   states(_p, _ppvar, _thread, _nt);
  }}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m1_7) - _p;  _dlist1[0] = &(Dm1_7) - _p;
 _slist1[1] = &(h1_7) - _p;  _dlist1[1] = &(Dh1_7) - _p;
 _slist1[2] = &(s1_7) - _p;  _dlist1[2] = &(Ds1_7) - _p;
 _slist1[3] = &(m1_8) - _p;  _dlist1[3] = &(Dm1_8) - _p;
 _slist1[4] = &(h1_8) - _p;  _dlist1[4] = &(Dh1_8) - _p;
 _slist1[5] = &(ndr) - _p;  _dlist1[5] = &(Dndr) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
