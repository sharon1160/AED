#include<iostream>
using namespace std;

template <typename T>

class RBTree{
	private:
		enum Color {BLACK , RED}; //usamos un enum para 
		class RBNode{
			public:
				T key;
				RBNode *left;
				RBNode *right;
				RBNode *p;  //padre
				Color color;
				RBNode(T key){
					this->key = key;
					this->color = Color::RED;
				}
				
		};
		RBNode *root;
		RBNode *nil;
		
		
		void rotateLeft(RBNode * x){
			RBNode * y = x->right;
			x->right = y->left;
			
			if(y->left != this->nil){
				y->left->p=x;
			}
			
			y->p = x->p;
			
			if(x->p == this->nil){
				this->root =y;
			}
			else if( x== x->p->left){
				x->p->left =y;
			}
			else{
				x->p->right = y;
			}
			y->left = x;
			x->p =y;
		}
		void rotateRight(RBNode * x){
			RBNode * y = x->left;
			x->left = y->right;
			if(y->right != this->nil){
				y->right->p=x;
			}
			y->p = x->p;
			if(x->p == this->nil){
				this->root =y;
			}
			else if( x== x->p->right){
				x->p->right =y;
			}
			else{
				x->p->left = y;
			}
			y->right = x;
			x->p =y;
		}
		void transplant(RBNode * u,RBNode * v){
			if(u->p == this->nil){
				this->root =v;
			}
			else if ( u == u->p->left){
				u->p->left =v;
			}
			else{
				u->p->right =v;
			}
			v->p = u->p;
		}
		void insertFixup(RBNode * z){
			RBNode * y;//TIO
			while(z->p->color== Color::RED){
				if(z->p == z->p->p->left){
					y=z->p->p->right;
					if(y->color == Color::RED){
						z->p->color = Color::BLACK;
						y->color = Color::BLACK;
						z->p->p->color= Color::RED;
						z=z->p->p;
					}
					else{
						if(z== z->p->right){
							z=z->p;
							rotateLeft(z);
						}
						z->p->color = Color::BLACK;
						z->p->p->color = Color::RED;
						rotateRight(z->p->p);
					}
				}
				else{
					y=z->p->p->left;
					if(y->color == Color::RED){
						z->p->color = Color::BLACK;
						y->color = Color::BLACK;
						z->p->p->color= Color::RED;
						z=z->p->p;
					}
					else{
						if(z== z->p->left){
							z=z->p;
							rotateRight(z);
						}
						z->p->color = Color::BLACK;
						z->p->p->color = Color::RED;
						rotateLeft(z->p->p);
					}										
					
				}
			}
		    this->root->color = Color::BLACK;	
		}
		
		void print(RBNode *t){
			if( t != this->nil ){
				print( t->left );

				cout<< t-> key <<"                COLOR :"<< t->color<< endl;
				print( t->right );
			}
			
		}
		
		void deleteFixup(RBNode * x){
			RBNode *w;
			while(x != this->root && x->color == Color::BLACK){
				if(x == x->p->left){
					w= x->p->right;
					if(w->color == Color::RED){
						w->color = Color::BLACK;
						x->p->color = Color::RED;
						rotateLeft(x->p);
						w = x->p->right;
					}
					if(w->left->color == Color::BLACK && w->right->color == Color::BLACK){
						w->color = Color::RED;
						x = x->p;
					}else{
						if(w->right->color == Color::BLACK){
							w->left->color = Color::BLACK;
                            w->color = Color::RED;
                            rotateRight(w);
                            w = x->p->right;
						}
						w->color = x->p->color;
                        x->p->color = Color::BLACK;
                        w->right->color = Color::BLACK;
                        rotateLeft(x->p);
                        x = this->root;
					}
				}
				else{
					w= x->p->left;
					if(w->color == Color::RED){
						w->color =Color::BLACK;
						x->p->color = Color::RED;
						rotateRight(x->p);
						w = x->p->left;
					}
					if(w->right->color == Color::BLACK && w->left->color == Color::BLACK){
						w->color = Color::RED;
						x = x->p;
					}else{
						if(w->left->color == Color::BLACK){
							w->right->color = Color::BLACK;
                            w->color = Color::RED;
                            rotateLeft(w);
                            w = x->p->left;
						}
						w->color = x->p->color;
                        x->p->color = Color::BLACK;
                        w->left->color = Color::BLACK;
                        rotateRight(x->p);
                        x = this->root;
					}
				}
			}
			x->color = Color::BLACK;
		}
	
	public:
		
		explicit RBTree(){
			this->nil = new RBNode(0);
			this->nil->color = Color::BLACK;
			this->nil->p = this->nil;
			this->root = this->nil;
		}
		~ RBTree(){
			delete this->root;
			delete this->nil;
		}

		RBNode *getTreeMinimum(RBNode * root){
			while(root->left != this->nil){
				root = root->left;
			}
			return root;
		}
		
        RBNode *getTreeMaximum(RBNode * root){
        	while(root->right != this->nil){
				root = root->right;
			}
			return root;
		}
		
        RBNode * getNode(T value){
        	RBNode * node = root;
        	while (node != this->nil && value != node->key) {
        		if (value < node->key){
        			node = node->left;
				}
				else{
					node = node->right;
				}
		    }
		    return node;
        }
		
		void insert(T value){
			RBNode * z = new RBNode(value);
			RBNode * y = this->nil;
			RBNode * x = this->root;
			while( x != this->nil){
				y=x;
				if(z->key < x->key ){
					x=x->left;
				}
				else{
					x=x->right;
				}
			}
			z->p = y;
			if( y == this->nil){
				this->root=z;
			}
			else if( z->key < y->key ){
				y->left =z;
			}			
			else{
				y->right = z;
			}
			z->left = this->nil;
			z->right = this->nil;
			z->color = Color::RED;
			insertFixup(z);//verificar
		}
		void mostrar (){
			print(root);
		}
		void remove(T value){
			RBNode *z= getNode(value);
			RBNode *y = z;
			RBNode *x;
			Color origColor = y->color;
			if(z->left == this->nil){
				x = z->right;
				transplant(z,z->right);
			}else if(z->right == this->nil){
				x = z->left;
				transplant(z,z->left);
			}else{
				y = getTreeMinimum(z->right);
				origColor = y->color;
				x = y->right;
				if(y->p == z){
					x->p = y;
				}else{
					transplant(y,y->right);
					y->right = z->right;
					y->right->p = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->p = y;
				y->color = z->color;
			}
			if(origColor == Color::BLACK){
				deleteFixup(x);
			}
			
		}
		
};
