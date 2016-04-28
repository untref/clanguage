revertir([],A,A).
revertir([H|T], A, R) :-
    revertir(T,[H|A],R).
