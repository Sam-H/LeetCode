#pragma once
#include <unordered_map>
#include <utility>

/* Definition for singly-linked list with a random pointer. */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{

		RandomListNode* newHead = nullptr;

		if (head != nullptr)
		{
			std::unordered_map<RandomListNode*, RandomListNode*>                        newNodesMap;
			std::unordered_map<RandomListNode*, std::vector<RandomListNode*>>           wantedNodesMap;
			std::unordered_map<RandomListNode*, RandomListNode*>::iterator              ItNewNodesMap;
			std::unordered_map<RandomListNode*, std::vector<RandomListNode*>>::iterator ItwantedNodesMap;
	
			RandomListNode* currNode = head;
			
			newHead = new RandomListNode(head->label);
			
			if (head->random == head)
			{
				newHead->random = newHead;
			} else
			{
				std::vector<RandomListNode*> vect(1, newHead);
				vect.reserve(10);
				wantedNodesMap.insert(std::pair < RandomListNode*, std::vector<RandomListNode*>>(head->random, vect));
			}

			newNodesMap.insert(std::pair<RandomListNode*, RandomListNode*>(head, newHead));

			RandomListNode* newNode = newHead;
	
			currNode = currNode->next; 

			while (currNode != nullptr)
			{
				// Create new node, register in map
				newNode->next = new RandomListNode(currNode->label);
				newNode = newNode->next;

				newNodesMap.insert(std::pair<RandomListNode*, RandomListNode*>(currNode, newNode));
	
				// Is there a random pointer ?
				if (currNode->random != nullptr)
				{
					if (currNode->random == currNode)
					{
						newNode->random = newNode;
					}
					else if ((ItNewNodesMap = newNodesMap.find(currNode->random)) != newNodesMap.end())
					{
						newNode->random = (*ItNewNodesMap).second;
					}
					else
					{
						if ((ItwantedNodesMap = wantedNodesMap.find(currNode->random)) != wantedNodesMap.end())
						{
							((*ItwantedNodesMap).second).push_back(newNode);
						}
						else
						{
							std::vector<RandomListNode*> vect(1, newNode);
							vect.reserve(10);
							wantedNodesMap.insert(std::pair < RandomListNode*, std::vector<RandomListNode*>>(currNode->random, vect));
						}
					}
				}
	
				// Am I pointed to by a random pointer ?
	
				if ((ItwantedNodesMap = wantedNodesMap.find(currNode)) != wantedNodesMap.end())
				{
					const std::pair < RandomListNode*, std::vector<RandomListNode*>> & pair = *ItwantedNodesMap;
					const std::vector<RandomListNode*> & vect = pair.second;
	
					for (std::vector<RandomListNode*>::const_iterator it = vect.begin(); it != vect.end(); ++it)
					{
						(*it)->random = newNode;
					}
				}

				currNode = currNode->next;
	
			}
		}

		return newHead;
	}

};