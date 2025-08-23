class Solution {
    public:
      Node* mergeTwoLists(Node* list1, Node* list2) {
          Node* dummyNode = new Node(-1);
          Node* temp = dummyNode;
  
          while(list1 != NULL && list2 != NULL)
          {
              if(list1->data<=list2->data)
              {
                  temp->bottom = list1;
                  list1 = list1->bottom;
              }
              else
              {
                  temp->bottom = list2;
                  list2 = list2->bottom;
              }
              temp = temp->bottom;
          }
          while(list1 != NULL)
          {
              temp->bottom = list1;
              list1 = list1->bottom;
              temp = temp->bottom;
          }
          while(list2 != NULL)
          {
              temp->bottom = list2;
              list2 = list2->bottom;
              temp = temp->bottom;
          }
  
          return dummyNode->bottom;
      }
      Node *flatten(Node *root) {
          // Your code here
          Node* dummyNode = new Node(-1);
          Node* temp = root;
          while(temp!=NULL)
          {
              dummyNode = mergeTwoLists(dummyNode,temp);
              temp = temp->next;
          }
          return dummyNode->bottom;
      }
  };