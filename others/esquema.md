# Printf: abstract

```
printf("%[__flags__][__width__][.__prec__]__type__");
```

*flags
	-: posicione o valor à esquerda
	+: o valor precedido de + ou -
	 : valor positivo precedido de caracter em branco
	0: preenche o valor com zeros
	#: preceder octais com 0, hex com 0x, mostrar ponto decimal

width.prec
	*: o próprio argumento da printf é a largura
	.numero: numero minimo de digitos para int, n de casas decimais para e ou f, num max de dig significaitvos para g, numero max de caracteres para significativos para s 
	.*: o proprio argumento da printf é o valor da precisão

||%|c|s|p|d,i|u,x,X|
|--|--|--|--|--|--|--|
|__+__|N.H|error|error|U.B|value with + or -|U.B|
|__-__|L.A|L.A|L.A|L.A|L.A|L.A|
|__0__|N.H|error|error|U.B|filled with 0 at left|filled with 0 at left|
| |N.H|error|error|U.B|value with ' ' or -|U.B|
|__#__|N.H|N.H|N.H|U.B|N.H||
|__.__|N.H|N.H|nothing printed|N.H|N.H|N.H|
|__.[num]__|N.H|error|maximum characteres to print|U.B|minimum digits (filled with 0 at left)|minimum digits (filled with 0 at left)|
|__[num]__|width|width|width|width|width|width|

`N.H` nothing happens
`L.A` left aligned
`U.B` undefined behavior
