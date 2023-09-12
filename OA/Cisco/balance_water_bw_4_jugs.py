from collections import deque

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def min_steps_to_target(jug_caps, initial_state, target_state):
    def is_valid_state(state):
        return all(0 <= x <= cap for x, cap in zip(state, jug_caps))

    def get_neighbors(state):
        neighbors = []
        for i in range(len(jug_caps)):
            for j in range(len(jug_caps)):
                if i != j:
                    next_state = list(state)
                    transfer = min(state[i], jug_caps[j] - state[j])
                    next_state[i] -= transfer
                    next_state[j] += transfer
                    if is_valid_state(next_state):
                        neighbors.append(tuple(next_state))
        return neighbors

    visited = set()
    initial_state = tuple(initial_state)
    target_state = tuple(target_state)

    if not is_valid_state(initial_state) or not is_valid_state(target_state):
        return -1  # Invalid initial or target state

    if initial_state == target_state:
        return 0  # Already at the target state

    queue = deque([(initial_state, 0)])

    while queue:
        current_state, steps = queue.popleft()

        for neighbor_state in get_neighbors(current_state):
            if neighbor_state == target_state:
                return steps + 1
            if neighbor_state not in visited:
                visited.add(neighbor_state)
                queue.append((neighbor_state, steps + 1))

    return -1  # Target state is unreachable

# Example usage:
jug_caps = [13, 12, 10, 5]
initial_state = [6, 6, 0, 0]
target_state = [12, 0, 0, 0]

result = min_steps_to_target(jug_caps, initial_state, target_state)
print("Minimum steps:", result)

