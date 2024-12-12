[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/e0PAH3hp)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11303477&assignment_repo_type=AssignmentRepo)
# Alumno: Chavez Balarezo Fabricio 
#

# Trie

Se le pide implementar lo siguiente:
- Trie en su versión simple para gestionar los hijos (simpletrie.h)
- Trie compacto para gestionar los hijos (patriciatrie.h)

1. Asegúrese que los algoritmos funcionen 
2. Realizar un análisis experimental variando el tamaño del diccionario (N). Para ello debe generar N palabras aleatorias de tamaño variable. 

## Análisis experimental del efecto de compactación en el Trie
| N    | Trie Simple (ms) | Trie Patricia(ms) |
|------|------------------|-------------------|
| 10^1 | 0.0001326        | 0.0004894         |
| 10^2 | 0.0001556        | 0.0006994         |
| 10^3 | 0.0001802        | 0.0008802         |
| 10^4 | 0.000214         | 0.0011498         |
| 10^5 | 0.0004556        | 0.001366          |
| 10^6 | 0.0005396        | 0.0016896         |
| 10^7 | 0.0008488        | 0.0021372         |
| 10^8 | 0.0009           | 0.0026            |

> Gráfico!
![Comparación](comparacion.png)

**Colocar en las celdas el tiempo de computo que se tomaria el algoritmo de búsqueda.**

NOT DELETE OR MODIFY  THE MAIN FILE. 
