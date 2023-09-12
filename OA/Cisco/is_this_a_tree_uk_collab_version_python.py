from collections import defaultdict

def more_than_2_children(child_of) -> bool:
	for parent, children in child_of.items():
		if len(children) > 2:
			return True
	return False

def duplicate_edges(child_of) -> bool:
	for parent, children in child_of.items():
		if (len(children) == 2 and children[0] == children[1]):
			return True
		for child in children:
			if child in child_of.keys() and parent in child_of[child]:
				return True
	
	return False

def dfs(curr, visited, child_of) -> bool:
	visited[ord(curr) - ord('A')] = 1
	for child in child_of[curr]:
		if visited[ord(child) - ord('A')] == 1:
			return True
		
		if (dfs(child, visited, child_of)):
			return True
	
	return False

def check_cycle(child_of) -> bool:
	visited = [0] * 26
	cnt = 0
	for node in range(26):
		if not visited[node] and chr(ord('A') + node) in child_of.keys():
			cnt += 1
			if (dfs(chr(ord('A') + node), visited, child_of)):
				return True
	
	return False

def multiple_roots(child_of) -> bool:
	# a node have multiple parents
	parent_of = defaultdict(str)
	for parent, children in child_of.items():
		for child in children:
			if parent_of[child] == '':
				parent_of[child] = parent
			else:
				return True
	
	return False

def gen_exp(curr, s, child_of):
	s.append('(')
	s.append(curr)
	for child in child_of[curr]:
		gen_exp(child, s, child_of)
	s.append(')')

# def gen_exp(curr, child_of):
#     if not child_of[curr]:
#         return '(' + curr + ')'
#     else:
#         result = '(' + curr
#         for child in child_of[curr]:
#             result += gen_exp(child, child_of) 
#         result += ')'
#         return result


def sort_util(child_of : defaultdict(list)) -> defaultdict(list):
	sorted_items = sorted(child_of.items())
	sorted_child_of = defaultdict(list)
	for key, values in sorted_items:
		sorted_child_of[key].extend(values)
	
	return sorted_child_of

def sExpression(nodes: str) -> str:
	child_of = defaultdict(list)
	for node in nodes.split(' '):
		child_of[node[1]].append(node[3])

	child_of = sort_util(child_of)
	if more_than_2_children(child_of):
		return "E1"
	
	if duplicate_edges(child_of):
		return "E2"
	
	if check_cycle(child_of):
		return "E3"
	
	if multiple_roots(child_of):
		return "E4"

	s = []
	gen_exp(next(iter(child_of)), s, child_of)
	return s
	# return gen_exp(next(iter(child_of)), child_of)



if __name__ == '__main__':
	nodes = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)"
	# nodes = "(A,B) (A,C) (B,D) (D,C)"
	print(''.join(sExpression(nodes)))