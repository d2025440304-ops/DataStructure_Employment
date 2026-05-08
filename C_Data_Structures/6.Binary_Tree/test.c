#include "Heap.h"

// void test1()
// {
//   int a[] = {9,8,7,6,6,5,4,3};
//   int size = sizeof(a)/sizeof(int);
//   HPInit(&hp);
//   for (int i = 0;i<size;i++)
//   {
//     HPpush(&hp,a[i]);
//   }
//
//   for (int i = 0;i<size;i++)
//   {
//     printf("%d ",hp.a[i]);
//   }
//   HPDestory(&hp);
// }

// void hpsort()
// {
//   int a[] = {9,8,7,6,6,5,4,3};
//   int size = sizeof(a)/sizeof(int);
//   HP hp;
//   HPInit(&hp);
//   for (int i = 0;i<size;i++)
//   {
//     HPpush(&hp,a[i]);
//   }
//   while(!HPempty(&hp))
//   {
//     printf("%d ",HPtop(&hp));
//     HPpop(&hp);
//   }
//   int i =0;
//   while(!HPempty(&hp))
//   {
//     a[i++] = HPtop(&hp);
//     HPpop(&hp);
//   }
// }

// void topk()
// {
//   int k;
//   scanf("%d",&k);
//   while (k--)
//   {
//     printf("%d ",HPtop(&hp));
//     HPpop(&hp);
//   }
// }
//
HP hp;

// void HeapSort0()
// {
//   //堆排序，降序-小根堆
//   int arr[] = {9,7,6,5,4,2,8};
//   int sz = sizeof(arr)/sizeof(int);
//   //默认第一个元素是合法的小根堆，在插入向上调整
//   //向上调整法
//   // for (int i = 1;i<sz;i++)
//   // {
//   //   //默认第一个元素是小根堆，对每一个元素都向上调整
//   //   AdjustUp(arr,i);//数组地址，下标
//   // }
//   for (int i = (sz-1-1)/2;i>=0;i--)
//   {
//     Adjustlow(arr,i,sz);
//   }
//   int end = sz-1;
//   while (end > 0)
//   {
//     Swap(&arr[0],&arr[end]);
//     Adjustlow(arr,0,end);
//     end--;
//   }
//
//   for (int i = 0;i<sz;i++)
//   {
//     printf("%d ",arr[i]);
//   }
//   printf("\n");
// }
//
// void Heap_Sort1()
// {
//   //升序-大根堆
//   int a[] = {4,3,5,6,2,7,9};
//   int sz = sizeof(a)/sizeof(a[0]);
//
// }
//
// void Topk()
// {
//   //找出一堆数据里前k个大的数，用小堆，只维护 k 个数据，比堆顶大就入堆
//   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625};
//   int sz = sizeof(arr)/sizeof(int);
//   int k = 10;
//   HPInit(&hp);
//   for (int i = 0;i < k;i++)
//   {
//     HPpush(&hp,arr[i]);
//   }
//
//   for (int i =k ;i<sz;i++)
//   {
//     int top = HPtop(&hp);
//     if (arr[i] > top)
//     {
//       HPpop(&hp);//删除堆顶，向下调整
//       HPpush(&hp,arr[i]);//插入，向上调整
//     }
//   }
//
//   for (int i = 0;i<k;i++)
//   {
//     int top = HPtop(&hp);
//     printf("%d ",top);
//     HPpop(&hp);
//   }
//   HPDestory(&hp);
// }


typedef int BTDataType;

typedef struct BinaryTreeNode
{
  BTDataType data;
  struct BinaryTreeNode * left;
  struct BinaryTreeNode * right;
}Treenode;

Treenode * BuyNode(BTDataType x)
{
  Treenode * NODE =  (Treenode*)malloc(sizeof(Treenode));
  if (NODE == NULL)
  {
    perror("malloc fail");
    exit(1);
  }
  NODE->data = x;
  NODE->left = NODE->right = NULL;
  return NODE;
}

Treenode * CreatBinaryTree()
{
  Treenode* node1 = BuyNode(1);
  Treenode* node2 = BuyNode(2);
  Treenode* node3 = BuyNode(3);
  Treenode* node4 = BuyNode(4);
  Treenode* node5 = BuyNode(5);
  Treenode* node6 = BuyNode(6);
  node1->left = node2;
  node1->right = node4;
  node2->left = node3;
  node4->left = node5;
  node4->right = node6;

  return node1;
}


//递归
//前序遍历 根 左 右
void Prevorder(Treenode * root)
{
  if (root == NULL)
  {
    printf("N ");
    return;
  }

  printf("%d ",root->data);

  Prevorder(root->left);
  Prevorder(root->right);

}

//中序遍历 左 根 右
void InOrder(Treenode * root)
{
  if (root == NULL)
  {
    printf("N ");
    return ;
  }

  InOrder(root->left);
  printf("%d ",root->data);
  InOrder(root->right);
}

//后序遍历 左 右 根
void AfOrder(Treenode * root)
{
  if (root == NULL)
  {
    printf("N ");
    return ;
  }

  AfOrder(root->left);
  AfOrder(root->right);
  printf("%d ",root->data);
}

//分治思想，一颗树的节点数等于左子树➕右子树➕自己，再去递归
int Treesize(Treenode *root)
{
  return root == NULL ? 0 :
        Treesize(root->left) + Treesize(root->right) + 1;
}


//分治思想，当一颗树是空时，它的叶子树是 0.当它只有一个节点的时候，它的叶子树是 0
//当它是根时，加起来就是 0，当它是子叶是，就加 1
int TreeleafSize(Treenode * root)
{
    if (root == NULL)
      return 0;

    if (root->left == NULL && root->right == NULL)
      return 1;

    return TreeleafSize(root->left)+TreeleafSize(root->right);
}


int main()
{
  // test1();
  // hpsort();
  // HeapSort0();
  // Topk();

  Treenode * root = CreatBinaryTree();
  Prevorder(root);
  printf("\n");
  return 0;
}