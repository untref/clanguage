padre(guillermo, rossi, walter).
padre(guillermo, rossi, lucia).
madre(beatriz, capusotto, walter).
madre(beatriz, capusotto, lucia).

apellido(N, A) :- padre(N, A, _).
apellido(N, A) :- madre(N, A, _).
apellido(N, A) :- padre(_,A,N).
