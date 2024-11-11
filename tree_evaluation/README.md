Pasos de Compilacion:
Para compilar y correr correctamente el programa, se deben seguir los siguientes pasos:
- Entrar a carpeta 'tree_evaluation'.
- Verificar la inclusion de los siguientes archivos .bin dentro de la carpeta tree_evaluation.
	keys_1024.bin y keys_sorted_1024.bin
	keys_32768.bin y keys_sorted_32768.bin
	keys_1048576.bin y keys_sorted_1048576.bin
	keys_33554432.bin y keys_sorted_1048576.bin
	queries_1000.bin
- Construir y entrar a carpeta 'build'
- Dentro de build ejecutar el comando 'cmake ..' en la terminal.
- Ejecutar comando 'make'
- Ejecutar comando './test'

----------------------------------------------------------------
Testeo:
Para probar distintos arboles, se puede editar 'test.cpp' comentar y descomentar las partes del codigo que corresponden a las declaraciones de los 'rbtree' disponiendo de trees::RB, trees::ABB y AVLtrees::AVL para asignar a los cuatro arboles que sobre los cuales se insertaran las llaves de cuatro archivos.
De mismo modo, se pueden elegir distintos archivos desde los cuales construir arboles, cambiando la declaracion de las cuatro variables 'data' se puede leer entre archivos 'keys' o 'keys_sorted'.
Distintos archivos .bin pueden ser utilizados como keys o queries especificando el path dentro del codigo como '../nombre_de_archivo' donde se desee, la variable 'questions' correspondiendo a la lectura del archivo para consultas, es decir uso de 'find()'.