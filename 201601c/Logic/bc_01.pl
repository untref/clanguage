estudia(lucas, ing_en_computacion).
estudia(veronica, ing_en_computacion).
estudia(veronica, derecho).
estudia(josefina, rrhh).

programa(Quien, Que) :-
    estudia(Quien, ing_en_computacion),
    Que = java.