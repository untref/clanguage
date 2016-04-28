miembro(H, [H|_]).
miembro(H, [_|T]) :-
    miembro(H,T).