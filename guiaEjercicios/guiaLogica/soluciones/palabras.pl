word(abalone,a,b,a,l,o,n,e).
word(abandon,a,b,a,n,d,o,n).
word(enhance,e,n,h,a,n,c,e).
word(anagram,a,n,a,g,r,a,m).
word(connect,c,o,n,n,e,c,t).
word(elegant,e,l,e,g,a,n,t).

solution(V1, H1, V2, H2, V3, H3) :- 
  word(V1, _, V11, _, V13, _, V15, _),
  word(H1, _, H11, _, H13, _, H15, _),
  word(V2, _, V21, _, V23, _, V25, _),
  word(H2, _, H21, _, H23, _, H25, _),
  word(V3, _, V31, _, V33, _, V35, _),
  word(H3, _, H31, _, H33, _, H35, _),
  V11 = H11, 
  V21 = H13,
  V31 = H15,
  V13 = H21,
  V23 = H23,
  V33 = H25,
  V15 = H31,
  V25 = H33,
  V35 = H35,
  H1 \= V1.
