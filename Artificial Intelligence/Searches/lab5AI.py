"""
Finding Nash Equilibrium in 2x2 Games
A Nash Equilibrium is a situation where no player can improve their payoff
by unilaterally changing their strategy, given the other player's strategy.
"""

import numpy as np

def find_nash_equilibrium(player1_payoffs, player2_payoffs):
    """
    Find all pure strategy Nash Equilibria in a 2x2 game.
    
    Parameters:
    -----------
    player1_payoffs : 2x2 numpy array
        Payoff matrix for Player 1 (row player).
        player1_payoffs[row, col] = payoff for Player 1 when they choose row 
        and Player 2 chooses column.
    
    player2_payoffs : 2x2 numpy array
        Payoff matrix for Player 2 (column player).
        player2_payoffs[row, col] = payoff for Player 2 when Player 1 chooses row
        and they choose column.
    
    Returns:
    --------
    equilibria : list of tuples
        List of (row, column) indices representing Nash Equilibria.
        Empty list if no pure strategy equilibrium exists.
    """
    
    print("Player 1 Payoff Matrix (Row Player):")
    print(player1_payoffs)
    print("\nPlayer 2 Payoff Matrix (Column Player):")
    print(player2_payoffs)
    print("\n" + "="*50)
    
    equilibria = []
    
    # Strategy names for better readability
    row_names = ["Top", "Bottom"]
    col_names = ["Left", "Right"]
    
    # Check all 4 possible strategy combinations (2x2 = 4)
    print("Checking all possible strategy combinations:\n")
    
    for i in range(2):  # Player 1's strategies (rows)
        for j in range(2):  # Player 2's strategies (columns)
            print(f"Checking strategy: Player 1 plays {row_names[i]}, Player 2 plays {col_names[j]}")
            
            # Check if Player 1 wants to deviate
            # Compare payoff for current strategy vs payoff if Player 1 changes to other row
            player1_current = player1_payoffs[i, j]
            player1_alternative = player1_payoffs[1 - i, j]  # 1-i gives the other row
            
            # Check if Player 2 wants to deviate
            # Compare payoff for current strategy vs payoff if Player 2 changes to other column
            player2_current = player2_payoffs[i, j]
            player2_alternative = player2_payoffs[i, 1 - j]  # 1-j gives the other column
            
            # A Nash Equilibrium exists if neither player wants to deviate
            player1_happy = player1_current >= player1_alternative
            player2_happy = player2_current >= player2_alternative
            
            print(f"  Player 1 payoff: {player1_current} vs alternative {player1_alternative} - {'No incentive to deviate' if player1_happy else 'Would prefer to deviate'}")
            print(f"  Player 2 payoff: {player2_current} vs alternative {player2_alternative} - {'No incentive to deviate' if player2_happy else 'Would prefer to deviate'}")
            
            if player1_happy and player2_happy:
                equilibria.append((i, j))
                print(f"  ✅ Nash Equilibrium found at ({row_names[i]}, {col_names[j]})!")
            else:
                print(f"  ❌ Not a Nash Equilibrium")
            print()
    
    return equilibria

def analyze_game(player1_payoffs, player2_payoffs, game_name=""):
    """
    Complete analysis of a 2x2 game including visualization.
    """
    if game_name:
        print(f"\n{'='*60}")
        print(f"ANALYZING: {game_name}")
        print(f"{'='*60}")
    
    # Find all Nash Equilibria
    equilibria = find_nash_equilibrium(player1_payoffs, player2_payoffs)
    
    # Report results
    print("RESULTS:")
    print("-" * 50)
    
    if not equilibria:
        print("No pure strategy Nash Equilibrium found!")
        print("This game might have a mixed strategy equilibrium.")
    else:
        print(f"Found {len(equilibria)} pure strategy Nash Equilibrium(s):")
        row_names = ["Top", "Bottom"]
        col_names = ["Left", "Right"]
        
        for i, (row, col) in enumerate(equilibria, 1):
            print(f"{i}. Player 1 plays {row_names[row]}, Player 2 plays {col_names[col]}")
            print(f"   Payoffs: Player 1 gets {player1_payoffs[row, col]}, Player 2 gets {player2_payoffs[row, col]}")
    
    print("\n" + "="*60 + "\n")
    return equilibria

def mixed_strategy_equilibrium(player1_payoffs, player2_payoffs):
    """
    Calculate mixed strategy Nash Equilibrium for 2x2 games.
    
    In mixed strategy equilibrium, each player randomizes their strategies
    to make the other player indifferent between their pure strategies.
    """
    print("Calculating Mixed Strategy Nash Equilibrium...")
    print("-" * 50)
    
    # Extract payoffs for easier reference
    # Player 1's payoffs when Player 2 plays Left (column 0)
    a = player1_payoffs[0, 0]  # Top, Left
    b = player1_payoffs[1, 0]  # Bottom, Left
    
    # Player 1's payoffs when Player 2 plays Right (column 1)
    c = player1_payoffs[0, 1]  # Top, Right
    d = player1_payoffs[1, 1]  # Bottom, Right
    
    # Player 2's payoffs when Player 1 plays Top (row 0)
    e = player2_payoffs[0, 0]  # Top, Left
    f = player2_payoffs[0, 1]  # Top, Right
    
    # Player 2's payoffs when Player 1 plays Bottom (row 1)
    g = player2_payoffs[1, 0]  # Bottom, Left
    h = player2_payoffs[1, 1]  # Bottom, Right
    
    # For Player 2 to be indifferent between Left and Right,
    # Player 1 must mix with probability p such that:
    # p*e + (1-p)*g = p*f + (1-p)*h
    # This gives: p = (h - g) / (e - f - g + h)
    
    denominator = e - f - g + h
    if denominator != 0:
        p = (h - g) / denominator
        # p should be between 0 and 1 for a valid mixed strategy
        if 0 <= p <= 1:
            # For Player 1 to be indifferent between Top and Bottom,
            # Player 2 must mix with probability q such that:
            # q*a + (1-q)*c = q*b + (1-q)*d
            # This gives: q = (d - c) / (a - b - c + d)
            
            denominator_q = a - b - c + d
            if denominator_q != 0:
                q = (d - c) / denominator_q
                if 0 <= q <= 1:
                    print(f"Mixed Strategy Nash Equilibrium found:")
                    print(f"Player 1 plays Top with probability {p:.2f} and Bottom with probability {1-p:.2f}")
                    print(f"Player 2 plays Left with probability {q:.2f} and Right with probability {1-q:.2f}")
                    print(f"\nExpected Payoffs:")
                    print(f"Player 1: {p*q*a + p*(1-q)*c + (1-p)*q*b + (1-p)*(1-q)*d:.2f}")
                    print(f"Player 2: {p*q*e + p*(1-q)*f + (1-p)*q*g + (1-p)*(1-q)*h:.2f}")
                    return (p, q)
    
    print("No valid mixed strategy equilibrium exists or calculation not applicable.")
    return None

# ============================================================================
# EXAMPLE GAMES
# ============================================================================

def prisoner_dilemma():
    """Classic Prisoner's Dilemma example."""
    print("\n" + "="*60)
    print("PRISONER'S DILEMMA")
    print("="*60)
    print("Strategies: Cooperate (C) = 0, Defect (D) = 1")
    
    # Payoff matrices
    # Typical payoffs: (Cooperate, Cooperate) = (-1, -1)
    #                  (Cooperate, Defect) = (-3, 0)
    #                  (Defect, Cooperate) = (0, -3)
    #                  (Defect, Defect) = (-2, -2)
    player1 = np.array([[-1, -3],  # Cooperate row
                        [0, -2]])  # Defect row
    
    player2 = np.array([[-1, 0],   # Cooperate column
                        [-3, -2]]) # Defect column
    
    analyze_game(player1, player2, "Prisoner's Dilemma")

def coordination_game():
    """Coordination game example (like choosing meeting points)."""
    print("\n" + "="*60)
    print("COORDINATION GAME")
    print("="*60)
    print("Strategies: Location A = 0, Location B = 1")
    
    # Both players want to coordinate (choose same location)
    player1 = np.array([[2, 0],   # Both at A: good payoff
                        [0, 1]])  # Both at B: okay payoff
    
    player2 = np.array([[2, 0],   # Both at A: good payoff
                        [0, 1]])  # Both at B: okay payoff
    
    equilibria = analyze_game(player1, player2, "Coordination Game")
    
    # Also calculate mixed strategy equilibrium
    mixed_strategy_equilibrium(player1, player2)
    
    return equilibria

def battle_of_sexes():
    """Battle of the Sexes game example."""
    print("\n" + "="*60)
    print("BATTLE OF THE SEXES")
    print("="*60)
    print("Strategies: Opera = 0, Football = 1")
    
    # Player 1 (husband) prefers Football, Player 2 (wife) prefers Opera
    # But both prefer to be together
    player1 = np.array([[1, 0],   # Both Opera: husband okay
                        [0, 2]])  # Both Football: husband happy
    
    player2 = np.array([[2, 0],   # Both Opera: wife happy
                        [0, 1]])  # Both Football: wife okay
    
    equilibria = analyze_game(player1, player2, "Battle of the Sexes")
    
    # Also calculate mixed strategy equilibrium
    mixed_strategy_equilibrium(player1, player2)
    
    return equilibria

def matching_pennies():
    """Matching Pennies game (no pure strategy equilibrium)."""
    print("\n" + "="*60)
    print("MATCHING PENNIES")
    print("="*60)
    print("Strategies: Heads = 0, Tails = 1")
    
    # Player 1 wants to match, Player 2 wants to mismatch
    player1 = np.array([[1, -1],   # Match: Player 1 wins
                        [-1, 1]])  # Mismatch: Player 1 loses
    
    player2 = np.array([[-1, 1],   # Mismatch: Player 2 wins
                        [1, -1]])  # Match: Player 2 loses
    
    equilibria = analyze_game(player1, player2, "Matching Pennies")
    
    # Calculate mixed strategy equilibrium (should exist)
    mixed_eq = mixed_strategy_equilibrium(player1, player2)
    
    return equilibria, mixed_eq

def main():
    """Run examples of different 2x2 games."""
    print("NASH EQUILIBRIUM FINDER FOR 2x2 GAMES")
    print("="*60)
    print("\nA Nash Equilibrium is a set of strategies where no player")
    print("can improve their payoff by unilaterally changing strategy.\n")
    
    # Run examples
    prisoner_dilemma()
    coordination_game()
    battle_of_sexes()
    matching_pennies()
    
    print("\n" + "="*60)
    print("CREATE YOUR OWN GAME")
    print("="*60)
    
    # Let the user create their own game
    try:
        print("\nEnter payoffs for a 2x2 game:")
        print("Format: Row 1: a,b  Row 2: c,d")
        
        # Get Player 1's payoffs
        print("\nPlayer 1 (Row Player) Payoffs:")
        p1_row1 = input("Enter Top row payoffs (format: payoff_left, payoff_right): ")
        p1_row2 = input("Enter Bottom row payoffs (format: payoff_left, payoff_right): ")
        
        # Get Player 2's payoffs
        print("\nPlayer 2 (Column Player) Payoffs:")
        p2_row1 = input("Enter Top row payoffs (format: payoff_left, payoff_right): ")
        p2_row2 = input("Enter Bottom row payoffs (format: payoff_left, payoff_right): ")
        
        # Parse inputs
        p1_r1 = [float(x.strip()) for x in p1_row1.split(',')]
        p1_r2 = [float(x.strip()) for x in p1_row2.split(',')]
        p2_r1 = [float(x.strip()) for x in p2_row1.split(',')]
        p2_r2 = [float(x.strip()) for x in p2_row2.split(',')]
        
        # Create matrices
        player1_custom = np.array([p1_r1, p1_r2])
        player2_custom = np.array([p2_r1, p2_r2])
        
        # Analyze the custom game
        analyze_game(player1_custom, player2_custom, "Custom Game")
        
        # Try to find mixed strategy equilibrium
        mixed_strategy_equilibrium(player1_custom, player2_custom)
        
    except Exception as e:
        print(f"Error: {e}")
        print("Using default example instead.")
        
        # Default example if user input fails
        player1_default = np.array([[3, 0], [5, 1]])
        player2_default = np.array([[3, 5], [0, 1]])
        analyze_game(player1_default, player2_default, "Default Example Game")

if __name__ == "__main__":
    main()
