miembro(X, [X|_]).
miembro(X, [_|T]) :- miembro(X, T).

a2b([], []).
a2b([a|Ta], [b|Tb]) :- a2b(Ta, Tb).

%% Param1: origen1
%% param2: origen2
%% param3: resultado
%%
concatenar([], L2, L2).
concatenar(L1, [], L1).
concatenar([H1|T1], [H2|T2], [H1,H2|R]) :- concatenar(T1, T2, R).

long([],A,A).
long([_|T], A, L) :- Anew is A + 1, long(T, Anew, L).

concatenar2([], L, L).
concatenar2([H|T], L2, [H|T3]) :- concatenar(T, L2, T3).


revertir([],A,A).
revertir([H|T], A, R) :-
    revertir(T,[H|A],R).

palindromo(P) :-
    revertir(P,[], Q),
    P = Q.

ultimo(X, [X]).
ultimo(X, [_|T]) :-
    ultimo(X,T).
    


