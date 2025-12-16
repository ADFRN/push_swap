# Push_swap

## 📋 Description

Push_swap est un projet d'algorithme de tri qui utilise deux piles (stack A et stack B) et un ensemble limité d'opérations pour trier des nombres entiers.

Le but est de trier les nombres de la pile A en ordre croissant avec le **minimum de mouvements possible**.

## 🎯 Objectif

- Recevoir une liste de nombres entiers en paramètres
- Trier ces nombres dans la pile A en utilisant uniquement les opérations autorisées
- Optimiser le nombre d'instructions pour obtenir le meilleur score

## 🔧 Operations autorisées

### Swap
- `sa` : swap le premier et deuxième élément de la pile A
- `sb` : swap le premier et deuxième élément de la pile B
- `ss` : `sa` et `sb` en même temps

### Push
- `pa` : prend le premier élément de B et le met sur A
- `pb` : prend le premier élément de A et le met sur B

### Rotate
- `ra` : décale tous les éléments de A vers le haut (le premier devient dernier)
- `rb` : décale tous les éléments de B vers le haut
- `rr` : `ra` et `rb` en même temps

### Reverse rotate
- `rra` : décale tous les éléments de A vers le bas (le dernier devient premier)
- `rrb` : décale tous les éléments de B vers le bas
- `rrr` : `rra` et `rrb` en même temps

## 🚀 Compilation et utilisation

```bash
# Compilation
make

# Exemples d'utilisation
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap 42 8 -15 0 23

# Test avec checker
ARG="3 2 1 5 4"; ./push_swap $ARG | ./checker_linux $ARG
```

## 📊 Algorithmes utilisés

Le programme adapte son algorithme en fonction du nombre d'éléments :

- **2-3 éléments** : Tri simple avec des opérations de base
- **4-5 éléments** : Tri optimisé pour petites listes
- **Plus de 5 éléments** : Algorithme radix sort (tri par bits)

## ✅ Gestion des erreurs

Le programme vérifie et gère :
- Les arguments non numériques
- Les doublons
- Les dépassements d'entiers (INT_MIN / INT_MAX)
- Les listes vides ou mal formatées

En cas d'erreur, le programme affiche `Error` sur la sortie d'erreur.

## 📁 Structure du projet

```
push_swap/
├── includes/       # Fichiers header
├── libft/          # Lbft
├── srcs/           # Code source
│   ├── operations/ # Opérations de pile
│   └── errors/     # Gestion d'erreurs
└── Makefile
```

## 🎓 Projet 42

Ce projet fait partie du cursus de l'école 42.
