*This project has been created as part of the 42 curriculum by nicorodr*

🔄 Push_swap
📝 Descripción
Push_swap es un proyecto de algoritmos en 42. El objetivo es ordenar una lista aleatoria de números enteros usando solo dos pilas (Stack A y Stack B) y un conjunto muy limitado de movimientos (swaps, pushes y rotaciones), logrando la secuencia de movimientos más corta posible.

Para este proyecto, decidí implementar una variante del Algoritmo del Turco (o algoritmo de costes). El proceso general que sigue mi programa es:

Indexar los números para simplificar su manejo.

Pasar casi todos los números de la Pila A a la Pila B, dejando solo 3.

Ordenar esos 3 números manualmente.

El motor principal: Calcular el "coste" exacto (en cantidad de movimientos) de devolver cada número de la Pila B a su posición correcta (Target) en la Pila A.

Seleccionar siempre el número más barato de mover, aprovechando los movimientos dobles (rr, rrr) para optimizar al máximo.

Ajustar la pila final para que el número menor quede en la cima.

Gracias a esta lógica, el programa logra ordenar 100 números muy por debajo del límite de 700 movimientos que exige la evaluación.

⚙️ Instrucciones de compilación y ejecución
El proyecto incluye un Makefile estándar que compila los archivos fuente respetando los flags de la escuela (-Wall -Wextra -Werror).

Compilar
Para generar el ejecutable, simplemente clona el repositorio y ejecuta en la terminal:

Bash
make
Otros comandos disponibles:

make clean: Elimina los archivos objeto (.o).

make fclean: Elimina los archivos objeto y el ejecutable push_swap.

make re: Hace un fclean seguido de un make.

Ejecutar
Pásale una lista de números enteros separados por espacios (o como un solo string entre comillas). El programa te devolverá la lista de movimientos para ordenarlos.

Bash
./push_swap 42 -5 19 0 3 99 -20 8 1 7
Comprobar (Checker)
Puedes usar el programa proporcionado por 42 para verificar que los movimientos generados realmente ordenan la lista:

Bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
(Si la pila queda ordenada correctamente, el checker imprimirá OK).

🧠 Recursos utilizados y uso de Inteligencia Artificial
Para desarrollar este proyecto he tenido que repasar a fondo el uso de Listas Enlazadas en C, punteros a punteros y la correcta gestión de memoria (evitando leaks con malloc y free).

Uso de IA (Gemini):
Cumpliendo con la política de transparencia, declaro que he utilizado la IA (Gemini) como tutor personal durante el desarrollo. No se utilizó para autogenerar el proyecto de cero ni para copiar y pegar un código final, sino de la siguiente manera:

Entendimiento teórico: La usé para visualizar mentalmente cómo funcionan los intercambios de nodos en C (el concepto de "no soltar una cuerda antes de agarrar la siguiente").

Estructuración por fases: Me ayudó a dividir el proyecto en metas más pequeñas (1. Parsing y validación, 2. Movimientos base, 3. Ordenar listas pequeñas, 4. Algoritmo de costes).

Debugging y Linker: Me asistió a la hora de leer y comprender errores de compilación (implicit declaration y undefined reference), ayudándome a organizar correctamente mis prototipos en el archivo .h (Header).

Ha sido una herramienta de aprendizaje invaluable para construir mi propio código paso a paso entendiendo la lógica detrás de cada movimiento.