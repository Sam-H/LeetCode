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
	
			while (currNode->next != nullptr)
			{
				// Create new node, register in map
				newNode->next = new RandomListNode(currNode->next->label);
				newNodesMap.insert(std::pair<RandomListNode*, RandomListNode*>(currNode->next, newNode->next));
	
				// Is there a random pointer ?
				if (currNode->next->random != nullptr)
				{
					if (currNode->next->random == currNode->next)
					{
						newNode->next->random = newNode->next;
					}
					else if ((ItNewNodesMap = newNodesMap.find(currNode->next->random)) != newNodesMap.end())
					{
						newNode->next->random = (*ItNewNodesMap).second;
					}
					else
					{
						if ((ItwantedNodesMap = wantedNodesMap.find(currNode->next->random)) != wantedNodesMap.end())
						{
							((*ItwantedNodesMap).second).push_back(newNode->next);
						}
						else
						{
							std::vector<RandomListNode*> vect(1, newNode->next);
							vect.reserve(10);
							wantedNodesMap.insert(std::pair < RandomListNode*, std::vector<RandomListNode*>>(currNode->next->random, vect));
						}
					}
				}
	
				// Am I pointed to by a random pointer ?
	
				if ((ItwantedNodesMap = wantedNodesMap.find(currNode->next)) != wantedNodesMap.end())
				{
					const std::pair < RandomListNode*, std::vector<RandomListNode*>> & pair = *ItwantedNodesMap;
					const std::vector<RandomListNode*> & vect = pair.second;
	
					for (std::vector<RandomListNode*>::const_iterator it = vect.begin(); it != vect.end(); ++it)
					{
						(*it)->random = newNode->next;
					}
				}
	
				// Link with new list
				currNode = currNode->next;
				newNode = newNode->next;
			}
	
		}

		return newHead;
	}

};