#include <iostream>
#include <vector>
#include <set>
#include <string>

class DFA
{
public:
  DFA(int numStates, int numAlphabets, std::set<int> finalStates, std::vector<std::vector<int>> transitions) : states(numStates), alphabets(numAlphabets), acceptingStates(std::move(finalStates)), transitionTable(std::move(transitions)) {}

  int states;                                    // Total number of states
  int alphabets;                                 // Number of input symbols
  std::set<int> acceptingStates;                 // Set of accepting states
  std::vector<std::vector<int>> transitionTable; // Transition table
};

bool areStatesEquivalent(const DFA &dfa, int state1, int state2, const std::vector<int> &partition)
{
  for (int input = 0; input < dfa.alphabets; input++)
  {
    int nextState1 = dfa.transitionTable[state1][input];
    int nextState2 = dfa.transitionTable[state2][input];
    if (partition[nextState1] != partition[nextState2])
    {
      return false;
    }
  }
  return true;
}

std::vector<int> minimizeDFA(const DFA &dfa)
{
  const int numStates = dfa.states;

  std::vector<int> initialPartition(numStates, -1);

  int acceptingGroup = *dfa.acceptingStates.begin(), nonAcceptingGroup = -1;
  for (int state : dfa.acceptingStates)
  {
    initialPartition[state] = acceptingGroup;
  }
  for (int state = 0; state < numStates; state++)
  {
    if (initialPartition[state] < 0)
    {
      if (nonAcceptingGroup < 0)
      {
        nonAcceptingGroup = state;
      }
      initialPartition[state] = nonAcceptingGroup;
    }
  }

  while (true)
  {
    std::vector<int> newPartition(numStates, -1);
    int currentState = 0;
    while (currentState < numStates)
    {
      newPartition[currentState] = currentState;
      int nextState = numStates;
      for (int state = currentState + 1; state < numStates; state++)
      {
        if (newPartition[state] >= 0)
          continue;
        if (initialPartition[currentState] == initialPartition[state] && areStatesEquivalent(dfa, currentState, state, initialPartition))
        {
          newPartition[state] = currentState;
        }
        else if (nextState == numStates)
        {
          nextState = state;
        }
      }
      currentState = nextState;
    }
    if (initialPartition == newPartition)
      break;
    initialPartition = newPartition;
  }

  return initialPartition;
}

int main()
{
  int numStates, numAlphabets;
  std::cout << "Enter the number of states: ";
  std::cin >> numStates;
  std::cout << "Enter the number of alphabets: ";
  std::cin >> numAlphabets;

  std::set<int> acceptingStates;
  int numAcceptingStates;
  std::cout << "Enter the number of accepting states: ";
  std::cin >> numAcceptingStates;
  std::cout << "Enter the accepting states (space-separated): ";
  for (int i = 0; i < numAcceptingStates; i++)
  {
    int state;
    std::cin >> state;
    acceptingStates.insert(state);
  }

  std::vector<std::vector<int>> transitions(numStates, std::vector<int>(numAlphabets));
  std::cout << "Enter the transition table (one row per state, space-separated values for each input):\n";
  for (int i = 0; i < numStates; i++)
  {
    std::cout << "State " << i << ": ";
    for (int j = 0; j < numAlphabets; j++)
    {
      std::cin >> transitions[i][j];
    }
  }

  DFA dfa(numStates, numAlphabets, acceptingStates, transitions);
  auto minimizedDFA = minimizeDFA(dfa);

  std::cout << "\nMinimized DFA Partition:\n";
  for (int state = 0; state < minimizedDFA.size(); state++)
  {
    std::cout << "State " << state << " -> Group " << minimizedDFA[state] << "\n";
  }

  return 0;
}
