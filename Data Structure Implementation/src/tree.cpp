#include "../include/tree.h"

template <typename T>
typename Tree<T>::Node* Tree<T>::bfs(T data, Node* root) const {
	Node* ptr = root;
	if (root == nullptr) ptr = t_root;
	std::queue<Node*> q;
	q.push(ptr);
	while(!q.empty()) {
		ptr = q.front(); q.pop();
		if (ptr->info == data) return ptr;
		if (ptr->left) q.push(ptr->left);
		if (ptr->right) q.push(ptr->right);
	}
	return nullptr;
}

template <typename T>
typename Tree<T>::Node* Tree<T>::dfs(T data, Node* root) const {
	Node* ptr = root;
	if (root == nullptr) ptr = t_root;
	std::stack<Node*> s;
	s.push(ptr);
	while(!s.empty()) {
		ptr = s.top(); s.pop();
		if (ptr->info == data) return ptr;
		if (ptr->left) s.push(ptr->left);
		if (ptr->right) s.push(ptr->right);
	}
	return nullptr;
}

template <typename T>
void Tree<T>::recursiveInOrderTraverse(Node* root) const {
	if (t_root == nullptr) return;
	if (!root) root = Tree<T>::t_root;
	if (root->left != nullptr) recursiveInOrderTraverse(root->left);
	std::cout << root->info << " ";
	if (root->right != nullptr) recursiveInOrderTraverse(root->right);
}

template <typename T>
void Tree<T>::recursivePreOrderTraverse(Node* root) const {
	if (!t_root) return;
	if (!root) root = t_root;
	std::cout << root->info << " ";
	if (root->left != nullptr) recursivePreOrderTraverse(root->left);
	if (root->right != nullptr) recursivePreOrderTraverse(root->right);
}

template <typename T>
void Tree<T>::recursivePostOrderTraverse(Node* root) const {
	if (!t_root) return;
	if (!root) root = t_root;
	if (root->left != nullptr) recursivePostOrderTraverse(root->left);
	if (root->right != nullptr) recursivePostOrderTraverse(root->right);
	std::cout << root->info << " ";
}

template <typename T>
void Tree<T>::iterativeInOrderTraverse() const {
	if (!t_root) return;
	std::stack<Node*> s;
	Node* curr = t_root;
	while (true) {
		if (curr != nullptr) {
			s.push(curr);
			curr = curr->left;
		} else {
			if(!s.empty()) {
				curr = s.top(); s.pop();
				std::cout << curr->info << " ";
				curr = curr->right;
			}
			else break;
		}
	}
}

template <typename T>
void Tree<T>::iterativePreOrderTraverse() const {
	if (!t_root) return;
	std::stack<Node*> s;
	Node* curr = t_root;
	s.push(curr);
	while(!s.empty()) {
		curr = s.top(); s.pop();
		std::cout << curr->info << " ";
		if (curr->right != nullptr) s.push(curr->right);
		if (curr->left != nullptr) s.push(curr->left);
	}
}

template <typename T>
void Tree<T>::iterativePostOrderTraverse() const {
	if (!t_root) return;
	std::stack<Node*> s;
	Node* curr = t_root;
	do {
		while (curr) {
			if (curr->right) s.push(curr->right);
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top(); s.pop();
		if(curr->right && !s.empty() && s.top() == curr->right) {
			s.pop();
			s.push(curr);
			curr = curr->right;
		} else {
			std::cout << curr->info << " ";
			curr = nullptr;
		}
	} while (!s.empty());
}

template <typename T>
void Tree<T>::levelOrderTraverse() const {
	Node *ptr = t_root;
	std::queue<Node*> q;
	q.push(ptr);
	while (!q.empty()) {
		ptr = q.front(); q.pop();
		std::cout << ptr->info << " ";
		if(ptr->left) q.push(ptr->left);
		if(ptr->right) q.push(ptr->right);
	}
	std::cout << std::endl;
}

template <typename T>
int Tree<T>::height(Node* root) const {
	Node *ptr = root;
	if (root == nullptr) ptr = t_root;
	std::map<Node*, int> level;
	std::queue<Node*> q;
	int height = 0;
	q.push(ptr);
	while (!q.empty()) {
		ptr = q.front(); q.pop();
		if (ptr->left) {
			q.push(ptr->left);
			level[ptr->left] = level[ptr] + 1;
			height = max(height, level[ptr->left]);
		}
		if (ptr->right) {
			q.push(ptr->right);
			level[ptr->right] = level[ptr] + 1;
			height = max(height, level[ptr->right]);
		}
	}
	return height;
}


template <typename T>
class bst : public Tree<T> {
public:
	bst& insert(T data);
	bst& del(T data);
	typename Tree<T>::Node* search(T data) const;
};

template <typename T>
bst<T>& bst<T>::insert(T data) {
	typename Tree<T>::Node *temp = new typename Tree<T>::Node(data);
	if(!Tree<T>::t_root) {
		Tree<T>::t_root = temp;
		return *this;
	}
	typename Tree<T>::Node *srt = Tree<T>::t_root;
	while(true) {
		if(srt->info > data) {
			if (srt->left == nullptr) {
				srt->left = temp;
				return *this;
			}
			srt = srt->left;
		} else if(srt->info < data) {
			if(srt->right == nullptr) {
				srt->right = temp;
				return *this;
			}
			srt = srt->right;
		}
		else if(srt->info == data) {
			// ReSharper disable once CppNonConsistentAcquisitionReclaimPair
			free(temp);
			return *this;
		}
	}
}

template <typename T>
bst<T>& bst<T>::del(T data) {
	typename Tree<T>::Node *ptr = Tree<T>::t_root;
	typename Tree<T>::Node *parent = Tree<T>::t_root;
	while(true) {
		if(ptr->info==data) {
			break;
		}
		if(ptr->info > data) {
			if (ptr->left) {
				parent = ptr;
				ptr = ptr->left;
			}
			else return *this;
		} else {
			if (ptr->right) {
				parent = ptr;
				ptr = ptr->right;
			}
			else return *this;
		}
	}
	if(ptr->left == nullptr && ptr->right == nullptr) {
		if (ptr == parent) {
			Tree<T>::t_root = nullptr;
			return *this;
		}
		if(parent->left == ptr) {
			free(ptr);
			parent->left = nullptr;
			return *this;
		}
		free(ptr);
		parent->right = nullptr;
		return *this;
	}
	if (ptr->left == nullptr) {
		if(parent->left == ptr) {
			parent->left = ptr->right;
			free(ptr);
		} else {
			parent->right = ptr->right;
			free(ptr);
		}
		return *this;
	}
	if(ptr->right == nullptr) {
		if(parent->left == ptr) {
			parent->left = ptr->left;
			free(ptr);
		} else {
			parent->right = ptr->left;
			free(ptr);
		}
		return *this;
	}
	typename Tree<T>::Node* successor = ptr->right;
	while (true) {
		if (successor->left) successor = successor->left;
		else break;
	}
	T t = successor->info;
	del(t);
	ptr->info = t;
	return *this;
}

template <typename T>
typename Tree<T>::Node* bst<T>::search(T data) const {
	if(!Tree<T>::t_root) return nullptr;
	typename Tree<T>::Node *srt = Tree<T>::t_root;
	while (true) {
		if(srt->info == data) return srt;
		if (srt->info > data) {
			if(!srt->left) return nullptr;
			srt = srt->left;
		} else if (srt->info < data) {
			if (!srt->right) return nullptr;
			srt = srt->right;
		}
	}
}