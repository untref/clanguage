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
viajar(Desde, Hasta) :- enAuto(Desde,Hasta).

%% Viajo en tren
viajar(Desde, Hasta) :- enTren(Desde,Hasta).

%% Viajo en avion
viajar(Desde, Hasta) :- enAvion(Desde,Hasta).

%% Combinaciones recursivas
viajar(Desde, Hasta) :-
    viajar(Desde, Escala),
    viajar(Escala, Hasta).

