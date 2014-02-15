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

