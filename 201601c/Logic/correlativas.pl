depende(matematica, ingreso).
depende(fisica, matematica).
depende(circuitos, fisica).
depende(algo1, matematica).
depende(algo2, algo1).
depende(algo3, algo2).

necesita(A,B) :-
    depende(A,B).
necesita(A,B) :-
    depende(A, C),
    depende(C, B).
