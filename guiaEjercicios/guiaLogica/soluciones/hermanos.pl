padre(guillermo, rossi, walter).
padre(guillermo, rossi, lucia).
padre(guillermo, rossi, camilla).

madre(beatriz, capusotto, lucia).
madre(beatriz, capusotto, walter).
madre(beatriz, capusotto, rodolfo).
madre(jimena, kaplan, camilla).
madre(irma, jusid, raquel).

hermano(H,I) :-
    padre(_,Apellido,H),
    padre(_,Apellido,I).
hermano(H,I) :-
    madre(_,Apellido,H),
    madre(_,Apellido,I).