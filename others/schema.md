# Printf: abstract

```
printf("%[__flags__][__width__][.__prec__]__type__");
```

||%|c|s|p|d,i|u|x|X|
|--|--|--|--|--|--|--|--|--|
|__+__|N.H|U.B|U.B|U.B|value preceeded by '+' or '-'|U.B|U.B|U.B|
|__-__|left aligned|left aligned|left aligned|left aligned|left aligned|left aligned|left aligned|left aligned|
|__0__|N.H|U.B|U.B|U.B|filled with '0' at left|filled with '0' at left|filled with '0' at left|filled with '0' at left|
|__[space]__|N.H|U.B|U.B|U.B|value preceeded by ' ' or '-'|U.B|U.B|U.B|
|__#__|N.H|U.B|U.B|U.B|N.H|U.B|value preceeded by '0x'|value preceeded by '0X'|
|__.__|N.H|N.H|nothing printed|N.H|N.H|N.H|N.H|N.H|
|__.[num]__|N.H|U.B|maximum characteres to print from string|U.B|minimum digits (filled with '0' at left)|minimum digits (filled with '0' at left)|minimum digits (filled with '0' at left)|minimum digits (filled with '0' at left)|
|__[num]__|width|width|width|width|width|width|width|width|

`N.H` nothing happens
`U.B` undefined behavior
