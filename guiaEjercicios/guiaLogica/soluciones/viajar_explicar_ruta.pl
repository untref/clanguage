enAuto(auckland,hamilton).
enAuto(hamilton,raglan).
enAuto(valmont,saarbruecken).
enAuto(valmont,metz).

enTren(metz,frankfurt).
enTren(saarbruecken,frankfurt).
enTren(metz,paris).
enTren(saarbruecken,paris).

enAvion(frankfurt,bangkok).
enAvion(frankfurt,singapore).
enAvion(paris,losAngeles).
enAvion(bangkok,auckland).
enAvion(singapore,auckland).
enAvion(losAngeles,auckland).

%% Viajo en auto
viajar(Desde, Hasta, ComoLego) :- enAuto(Desde,Hasta), ComoLego = ir(enAuto(Desde,Hasta)).

%% Viajo en tren
viajar(Desde, Hasta, ComoLego) :- enTren(Desde,Hasta), ComoLego = ir(enTren(Desde,Hasta)).

%% Viajo en avion
viajar(Desde, Hasta, ComoLego) :- enAvion(Desde,Hasta), ComoLego = ir(enAvion(Desde,Hasta)).

%% Combinacion auto - tren
viajar(Desde, Hasta, ComoLego) :-
   enAuto(Desde, Escala),
   enTren(Escala, Hasta),
   ComoLego = ir(enTren(Escala,Hasta), ir(enAuto(Desde,Escala))).

%% Combinacion tren - avion
viajar(Desde, Hasta, ComoLego) :-
  enTren(Desde, Escala),
  enAvion(Escala, Hasta),
  ComoLego = ir(enAvion(Escala,Hasta), ir(enTren(Desde,Escala))).

%% Combinaciones recursivas
viajar(Desde, Hasta, ComoLego) :-
    viajar(Desde, Escala, S0),
    viajar(Escala, Hasta, S1),
    ComoLego = ir(S0,S1).

