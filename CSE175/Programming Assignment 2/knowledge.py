#
# knowledge.py
#
# This file contains axioms for a midnight murder by monsters knowledge base.
#
# These sentences use the following ontology.
#
#   Bob, Celene, Lin, Mario, Maurice, Mildred : constants for individuals
#   Pale, Blue, Green, Purple : constants for skin complexion colors
#
#   Bitten(x) : true iff x has been bitten
#   Boils(x) : true iff the skin of x has boils
#   Cold(x) : true iff the body of x is cold to the touch
#   Complexion(x, y) : true iff the skin of x has the complexion y
#   Dead(x) : true iff x is dead
#   Disemboweled(x) : true iff the body of x is missing internal organs
#   Dismembered(x) : true iff the body of x is missing limbs
#   Drained(x) : true iff the body of x has been drained of blood
#   Eaten(x) : true iff x has been eaten
#   Incomplete(x) : true iff the body of x is missing parts
#   Intact(x) : true iff the body of x is relatively whole and intact
#   Killed(x, y) : true iff x murdered y
#   Monster(x) : true iff x is a monster
#   Person(x) : true iff x is a person
#   Poisoned(x) : true iff x has been poisoned
#   Present(x) : true iff x was present at the crime scene
#   Punctured(x) : true iff the body of x has puncture wounds
#   Suspect(x) : true iff x is a murder suspect
#   Vampire(x) : true iff x is a vampire
#   Victim(x) : true iff x was the victim of a murder
#   Werewolf(x) : true iff x is a werewolf
#   Witch(x) : true iff x is a witch
#
# No other constants, functions, or predicates should be used in the axioms
# contained in this file. All axioms must be definite clauses.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# PLACE ANY COMMENTS, INCLUDING ACKNOWLEDGMENTS, HERE
#
# PLACE YOUR NAME AND THE DATE HERE
#


# An Example from Russell & Norvig (2020)

# noinspection SpellCheckingInspection
crime_sentences = ['(American(x) & Weapon(y) & Sells(x, y, z) & Hostile(z)) ==> Criminal(x)',
                   'Owns(Nono, M1)',
                   'Missile(M1)',
                   '(Missile(x) & Owns(Nono, x)) ==> Sells(West, x, Nono)',
                   'Missile(x) ==> Weapon(x)',
                   'Enemy(x, America) ==> Hostile(x)',
                   'American(West)',
                   'Enemy(Nono, America)']


# Midnight Murder by Monsters Sentences

# The first-order logic definite clauses below are intended to express the
# following knowledge.
#
# Celene is a vampire.
# Mario is a werewolf.
# Mildred is a witch.
# Bob, Lin, and Maurice are people.
# A person who is dead is a victim.
# All vampires, werewolves, and witches are monsters.
# Any monster present at the crime scene is a suspect.
# If a vampire is suspected and the victim was bitten, then
#   the vampire killed the victim.
# If a werewolf is suspected and the victim was eaten, then
#   the werewolf killed the victim.
# If a witch is suspected and the victim was poisoned, then
#   the witch killed the victim.
# If a victim is drained of blood but has an intact body, then
#   the victim was bitten.
# If a victim is drained of blood and has body pieces missing (i.e., is
#   incomplete), then the victim was eaten.
# If a victim's body is intact, and the victim's skin complexion is
#   green, blue, or purple, or if it is pale with boils, then
#   the victim was poisoned.
# If a victim's skin complexion is pale and the body is either
#   cold or punctured, then the victim is drained of blood.
# If a victim's body is complete (i.e., not incomplete), then
#   it is not dismembered or disemboweled.

# PLACE YOUR FOL SENTENCES IN THIS LIST

monster_sentences = []
