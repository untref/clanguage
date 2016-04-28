concatenar2([], L, L).
concatenar2([H|T], L2, [H|T3]) :- concatenar(T, L2, T3).

