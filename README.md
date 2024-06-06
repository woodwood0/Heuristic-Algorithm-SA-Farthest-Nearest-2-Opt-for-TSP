# Heuristic Algorithm (SA/Farthest/Nearest/2-Opt) for TSP

以Farthest Insertion最遠插入法與Nearest Insertion最近插入法，分別求取旅行銷售員問題（TSP）的初步解，後以2-Opt局部搜尋法與Simulated Annealing模擬退火法分別改善結果。
<br>

## Farthest / Nearest 插入法
### 流程

1. **初始化數據集**<br>
   將所有節點座標與各點間的距離整理成矩陣，從第一個節點開始。<br>

2. **選擇節點**<br>
   選擇不包含在次迴路內的節點 k，最遠插入法使其至次迴路內的所有點之距離為最大（最近插入法使其至次迴路內的所有點之距離為最小）。<br>

3. **插入節點**<br>
    從次迴路中找出一節線 i-j，使節點 k 插入後所增加的路徑成本最小。<br>

4. **直到所有節點被造訪**<br>
   重複步驟2 及步驟3，直到所有節點形成單一封閉的迴路為止。<br>

### 檔案說明
- 輸入資料 : 編碼方式如圖。<br>
![資料說明](https://github.com/woodwood0/Heuristic-Algorithm-SA-Farthest-Nearest-2-Opt-for-TSP/assets/171545924/94e613e8-c134-4b32-9ccc-6e52eeac7ecc)
<br>
<br>

## 2-Opt 局部搜尋法
### 流程

0. **取得初步解**<br>
   針對插入法的解進行改善。<br>

1. **選擇並交換節線**<br>
   尋找哪兩條節線交換後能使總路徑減少最多，確認若交換後可以減少總路徑則進行交換。<br>

2. **直到總路徑無法再減少**<br>
   重複前步驟1，直到所有能使總路徑減少的可能交換完畢為止。<br>
<br>
<br>

## SA 模擬退火法
### 流程

0. **取得初步解**<br>
   針對插入法的解進行改善。<br>

1. **初始化參數**<br>
   初始化起始溫度、結束溫度、溫度變化率、概率選擇上限等參數。<br>

2. **隨機交換節點**<br>
   在原路徑上隨機交換二節點以得到新路徑。<br>

3. **接受路徑**<br>
   比較新舊路徑並擇優，若新路徑比舊路徑差，則按一定概率接受較差解。<br>

4. **直到終止條件達成**<br>
   重複步驟2 及步驟3，直到起始溫度達結束溫度，或隨機接受次數達上限，則結束演算法。

