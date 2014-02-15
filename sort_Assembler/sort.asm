#SimuProc 1.4.3.0
;-ordena los enteros en la posicion 500+
;-ordena los flotantes en la posicion 800+
;-los numeros enteros son precedidos por un 0
;-los numeros flotantes son precedidos por un 1
;-si se encuentra un un numero 2 (10) en la posicion
; de la diferenciacion, se finaliza el programa

mov bx,202
;bx = recorrido
ldb 300
;ax = memoria[300+recorrido]
cmp 200
;if(ax==cEntero)
jeq 9
;then goto 9
cmp 201
;if(ax==cFlotante)
jeq 015
;then goto 015
cmp 205
;if(ax==terminación)
jeq 27
;then goto 27
hlt
;end

;lectura entero()
lda 200
;ax = cEntero
mov bx,203
;bx = posicionamientoEntero
stb 500
;memoria[500+posicionamientoEnteros]=ax
inc 203
;posicionamientoEntero++
inc 202
;recorrido++
mov bx,202
;bx = recorrido
ldb 300
;ax = memoria[300+bx]
mov bx,203
;bx = posicionamientoEntero
stb 500
;memoria[500+posicionamientoEnteros]=ax
inc 203
;posicionamientoEntero++
inc 202
;recorrido++
jmp 0
;goto 0


;lectura flotante()
lda 201
;ax = cFlotante
mov bx,204
;bx = posicionamientoFlotante
stb 800
;memoria[800+posicionamientoEnteros]=ax
inc 204
;posicionamientoFlotante++
inc 202
;recorrido++
mov bx,202
;bx = recorrido
ldb 300
;ax = memoria[300+bx]
mov bx,204
;bx = posicionamientoFlotante
stb 800
;memoria[800+posicionamientoFlotante]=ax
inc 204
;posicionamientoFlotante++
inc 202
;recorrido++
mov bx,202
;bx = recorrido
ldb 300
;ax = memoria[300+bx]
mov bx,204
;bx = posicionamientoFlotante
stb 800
;memoria[800+posicionamientoFlotante]=ax
inc 204
;posicionamientoFlotante++
inc 202
;recorrido++
jmp 0
;goto 0

;poner terminaciones()
lda 205
;ax = terminación
mov bx,203
;bx = posicionamientoEntero
stb 500
;memoria[500+posicionamientoEnteros]=ax
lda 205
;ax = terminación
mov bx,204
;bx = posicionamientoFlotante
stb 800
;memoria[800+posicionamientoEnteros]=ax

;booble sort int()

mov bx,206
;bx=recorridoIntBooble
ldb 500
; ax = memoria[bx + 500]
sta 20A
; aux1 = ax
lda 205
; ax = terminacion
cmp 20A
;
jeq 063
;*
mov bx,206
; bx =
ldb 500
sta 20A
lda 205
cmp 20A
jeq 05B
;z

inc 206
mov bx,206

ldb 500
sta 208
inc 206
mov bx,206
ldb 500
sta 20A
lda 205
cmp 20A
jeq 05B
;goto z
inc 206

mov bx,206
ldb 500
sta 209
lda 208
cmp 209
jma 04D
;goto x
jme 059
;goto y
jeq 059
;goto y
;cambio
;aqui x
dec 206
dec 206
lda 209
mov bx,206
stb 500
inc 206
inc 206
lda 208
mov bx,206
stb 500
dec 206
jmp 033
;no cambia
;aqui y
dec 206
jmp 033
;fin iteración
;aqui z
dec 206
dec 206
lda 205
mov bx,206
stb 500
lda 200
sta 206
jmp 02D

;booble sort FLotante()

mov bx,207;v
;aqui v
;bx=recorrido flotante Booble
ldb 800
; ax = memoria[bx + 800]
sta 20A
; aux1 = ax
lda 205
; ax = terminacion
cmp 20A
;
jeq 0B5
;* cargar numero
mov bx,207
ldb 800
sta 20A
lda 205
cmp 20A
;compara indicador1 con terminal
jeq 0ab
;goto z
inc 207
;int1

mov bx,207
ldb 800
;carga entero1
sta 208
;guarda en temp1
inc 207
;deci1

mov bx,207
ldb 800
;carga decimal1
sta 20C
;guarda en decimal1
inc 207
;indicador2

mov bx,207
ldb 800
;carga indicador2
sta 20A
;guarda en auxiliar1
inc 207
;int 2

lda 205
cmp 20A
;compara indicador2 con terminal
jeq 0ab
;goto z

mov bx,207
ldb 800
;carga entero2
sta 209
;guarda en temp2
inc 207
;decimal 2

mov bx,207
ldb 800
;carga deci2
sta 20D
;guarda en decimal2

lda 209
cmp 208
;comparacion entre parte entera

jma 0a2
;goto x

jme 08b
;goto y

jeq 0a5
;goto w

;cambio
;aqui x mayor
dec 207
;int2
dec 207
;indi2
dec 207
;deci1
dec 207
;int1
lda 209
mov bx,207
stb 800
;entrega a int1 tmp2
inc 207
;deci1
lda 20D
mov bx,207
stb 800
;entrega a decimal1 deci2
inc 207
;indica2
inc 207
;int2
lda 208
mov bx,207
stb 800
;entrega a int2 tmp1
inc 207
;dec2
lda 20C
mov bx,207
stb 800
;entrega a decimal2 deci1
dec 207
;int2
dec 207
;indica2
jmp 069
;go to *

;no cambia
;aqui y
dec 207
;int2
dec 207
;ind2
jmp 069

;aqui w

lda 20C
cmp 20D
;comparacion entre parte decimal

jma 08b
;goto x

jme 0a2
;goto y

jeq 0a2
;goto y

jmp 069
;go to *


;variables y constantes
#200
0
;constante cEntero 200
1
;constante cFlotantes 201
0
;variable recorrido 202
0
;variable posicionamientoEntero 203
0
;variable posicionamientoFlotante 204
10
;constante terminación 205
0
;variable recorrido entero sort 206

;numeros a analizar
#300
0
101
0
11
0
1
1
110
101
1
1101111
101111
1
11011
11111
10

