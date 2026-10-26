import numpy as np

# Task 1: Build a Toy HMM

print("TASK 1: Toy HMM Setup")

# Define state and observation spaces
states = ['Sunny', 'Rainy']
observations = ['Walk', 'Shop', 'Clean']

state_map = {s: i for i, s in enumerate(states)}
obs_map = {o: i for i, o in enumerate(observations)}

# Initial State Probabilities (pi)
pi = np.array([0.6, 0.4])

# Transition Matrix A (Rows: Current State, Cols: Next State)
# Sunny -> Sunny: 0.7, Sunny -> Rainy: 0.3
# Rainy -> Sunny: 0.4, Rainy -> Rainy: 0.6
A = np.array([
    [0.7, 0.3],
    [0.4, 0.6]
])

# Emission Matrix B (Rows: Hidden State, Cols: Observation)
# Sunny: Walk=0.6, Shop=0.3, Clean=0.1
# Rainy: Walk=0.1, Shop=0.4, Clean=0.5
B = np.array([
    [0.6, 0.3, 0.1],
    [0.1, 0.4, 0.5]
])

print("States:", states)
print("Observations:", observations)
print("\nInitial State Distribution (pi):\n", pi)
print("\nTransition Matrix (A):\n", A)
print("\nEmission Matrix (B):\n", B)

# Task 2: Implement & Run Viterbi

print("\nTASK 2: Viterbi Decoding")

def viterbi(obs_seq, pi, A, B, state_map, obs_map):
    N = len(states)
    T = len(obs_seq)
    
    # Convert string observations to indices
    obs_idx = [obs_map[o] for o in obs_seq]
    
    # DP Tables
    V = np.zeros((N, T))
    backpointer = np.zeros((N, T), dtype=int)
    
    # Initialization (t = 0)
    V[:, 0] = pi * B[:, obs_idx[0]]
    
    # Recursion (t = 1 to T-1)
    for t in range(1, T):
        for s in range(N):
            prob = V[:, t-1] * A[:, s] * B[s, obs_idx[t]]
            V[s, t] = np.max(prob)
            backpointer[s, t] = np.argmax(V[:, t-1] * A[:, s])
            
    # Traceback
    best_last_state = np.argmax(V[:, T-1])
    best_prob = V[best_last_state, T-1]
    
    best_path_idx = [best_last_state]
    for t in range(T-1, 0, -1):
        best_last_state = backpointer[best_last_state, t]
        best_path_idx.insert(0, best_last_state)
        
    best_path = [states[i] for i in best_path_idx]
    return best_path, best_prob, V

obs_sequence = ['Walk', 'Shop', 'Clean', 'Walk']
path, prob, V_table = viterbi(obs_sequence, pi, A, B, state_map, obs_map)

print(f"Observation Sequence: {obs_sequence}")
print(f"Most Likely Hidden State Path: {path}")
print(f"Probability of Best Path: {prob:.6f}")


# Task 3: Parameter Sensitivity

print("\nTASK 3: Parameter Sensitivity")

# Modified Transition Matrix (Higher frequency of switching weather)
A_high = np.array([
    [0.2,0.8],  # Sunny -> Sunny: 0.2, Sunny -> Rainy: 0.8
    [0.7,0.3]   # Rainy -> Sunny: 0.7, Rainy -> Rainy: 0.3
])

path_mod, prob_mod, _ = viterbi(obs_sequence, pi, A_high, B, state_map, obs_map)

print(f"New Most Likely Path: {path_mod}")
print(f"New Best Path Probability: {prob_mod:.6f}")

# Task 4: Forward Algorithm

print("\ntask 4:Forward Algorithm")

def forward(obs_seq, pi, A, B, state_map, obs_map):
    N = len(states)
    T = len(obs_seq)
    obs_idx = [obs_map[o] for o in obs_seq]
    
    alpha = np.zeros((N, T))
    
    # Initialization
    alpha[:, 0] = pi * B[:, obs_idx[0]]
    
    # Induction
    for t in range(1, T):
        for s in range(N):
            alpha[s, t] = np.sum(alpha[:, t-1] * A[:, s]) * B[s, obs_idx[t]]
            
    # Termination
    total_prob = np.sum(alpha[:, T-1])
    return total_prob

fwd_prob = forward(obs_sequence, pi, A, B, state_map, obs_map)
print(f"Forward Algorithm Probability: {fwd_prob:.6f}")
print(f"Viterbi Best Path Probability: {prob:.6f}")

# Task 5: Mini Application

print("\ntask 5: Mini application")

# Student Activity Model
appStates = ['Study', 'Play', 'Sleep']
appObs = ['Notes', 'Games', 'Yawn']

app_state_map = {s: i for i, s in enumerate(appStates)}
app_obs_map = {o: i for i, o in enumerate(appObs)}

pi_app = np.array([0.5, 0.3, 0.2])

A_app = np.array([
    [0.6, 0.3, 0.1],  # Study -> Study, Play, Sleep
    [0.2, 0.5, 0.3],  # Play -> Study, Play, Sleep
    [0.1, 0.1, 0.8]   # Sleep -> Study, Play, Sleep
])

B_app = np.array([
    [0.7, 0.1, 0.2],  # Study: Notes, Games, Yawn
    [0.1, 0.8, 0.1],  # Play: Notes, Games, Yawn
    [0.05, 0.05, 0.9] # Sleep: Notes, Games, Yawn
])

app_sequence = ['Notes', 'Games', 'Yawn', 'Yawn']

# Running Viterbi for Mini Application
N_app = len(appStates)
T_app = len(app_sequence)
obs_idx_app = [app_obs_map[o] for o in app_sequence]

V_app = np.zeros((N_app, T_app))
bp_app = np.zeros((N_app, T_app), dtype=int)

V_app[:, 0] = pi_app * B_app[:, obs_idx_app[0]]

for t in range(1, T_app):
    for s in range(N_app):
        V_app[s, t] = np.max(V_app[:, t-1] * A_app[:, s] * B_app[s, obs_idx_app[t]])
        bp_app[s, t] = np.argmax(V_app[:, t-1] * A_app[:, s])

best_last = np.argmax(V_app[:, T_app-1])
app_prob = V_app[best_last, T_app-1]
app_path_idx = [best_last]

for t in range(T_app-1, 0, -1):
    best_last = bp_app[best_last, t]
    app_path_idx.insert(0, best_last)

app_path = [appStates[i] for i in app_path_idx]

print(f"Mini-App Sequence: {app_sequence}")
print(f"Decoded State Path: {app_path}")
print(f"Path Probability: {app_prob:.6f}")