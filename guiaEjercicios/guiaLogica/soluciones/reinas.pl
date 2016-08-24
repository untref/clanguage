tablero([q(3,1), q(6,2), q(4,3), q(2,4), q(8,5), q(5,6), q(7,7), q(1,8)]).

ataca(q(X, _), q(X, _)).
ataca(q(_, Y), q(_, Y)).
ataca( q(A,B), q(C,D) ) :-
    Dx is A - C,
    Dy is B - D,
    M is abs(Dy / Dx),
    M = 1.



novalido(T) :-
    member(C0, T),
    member(C1, T),
    not(C0 = C1),
    ataca(C0, C1).

