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

