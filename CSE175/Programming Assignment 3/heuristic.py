#
# heuristic.py
#
# This Python script file provides two functions in support of minimax search
# using the expected value of game states. First, the file provides the
# function "expected_value_over_delays". This function takes as an argument
# a state of game play in which the current player has just selected an
# action. The function calculates the expected value of the state over all
# possible random results determining the amount of time before the
# Guardian changes gaze direction. This function calculates this value
# regardless of whose turn it is. The value of game states that result from
# different random outcomes is determined by calling "value". Second, the
# file provides a heuristic evaluation function for non-terminal game states.
# The heuristic value returned is between "max_payoff" (best for the
# computer player) and negative one times that value (best for the opponent).
# The heuristic function may be applied to any state of play. It uses
# features of the game state to predict the game payoff without performing
# any look-ahead search.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# PLACE ANY COMMENTS, INCLUDING ACKNOWLEDGMENTS, HERE
#
# PLACE YOUR NAME AND THE DATE HERE
#


from parameters import *
from minimax import probability_of_time
from minimax import value


def expected_value_over_delays(state, ply):
    """Calculate the expected utility over all possible randomly selected
    Guardian delay times, ranging from 2 to 5 steps. Return this expected
    utility value. This represents how many steps behind the player that the guardian is!!
    This function is only called when ply < max_ply."""
    val = 0.0

    # PLACE YOUR CODE HERE
    # Note that the value of "ply" must be passed along, without
    # modification, to any function calls that calculate the value 
    # of a state.

    for guardian_delay in range(2, 6):
        # update the time remaining
        state.time_remaining = guardian_delay
        # calculate the expected utility of the given state
        expected_utility = probability_of_time(guardian_delay) * value(state, ply)
        val = val + expected_utility
  
    return val


def heuristic_value(state):
    """Return an estimate of the expected payoff for the given state of
    game play without performing any look-ahead search. This value must
    be between the maximum payoff value and the additive inverse of the
    maximum payoff (-max_payoff < expected_payoff < max_payoff). 
    This function is only used when ply >= max_ply."""
    val = 0.0

    """A value of a given state of play"""
    # this doesn't work
    #val = -(state.action * state.w_loc + max_payoff)

    return val
