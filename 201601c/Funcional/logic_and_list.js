
var TRUE = function(x) {
  return function(y) {
    return x;
  }
};

var FALSE = function(x) {
  return function(y) {
    return y;
  }
};

var NOT = function(p) {
    return p(FALSE)(TRUE);
};

var IF = function(p) {
    return function(a) {
        return function (b) {
            return p(a)(b)
        };
    };
}

var AND = function(p) {
    return function(q) {
        return p(q)(p);
    };
};

var OR = function(p) {
    return function(q) {
        return p(p)(q);
    };
};

var PAIR = function(a) {
    return function(b) {
        return function(p) {
            return p(a)(b);
        };
    };
};

var FIRST = function(p) {
    return p(TRUE);
};

var SECOND = function(p) {
    return p(FALSE);
};

var NIL = FALSE;
var CONS = PAIR;
var HEAD = FIRST;
var TAIL = SECOND;
