# Fillit
Trouver la plus petit map possible pour le remplissage des tetriminos

Le projet Consiste principalement à decouvrir la notion du backtracking, d'analyse de fichier/arguments mais aussi le travail
en groupe.

Le but etant de trouver le plus petit carré possible pour X tetriminos donnée .
les informations du tetriminos sont stocké dans un fichier.
Chaque tetriminos est unique ici même si ils ont la même formes.

### Exemple de fichier :
```
####
....
....
....
  
....
.#..
##..
.#..

##..
.##.
....
....
```
  ### Nous avons:
```
AAAA
...B
CCBB
.CCB
```
Si le fichier passé est invalide , alors un message d'erreur s'affiche et termine son execution.
Nous l'analysons en premiers temps, puis nous le résolvons (on print l'alphabet pour se repèrer).
