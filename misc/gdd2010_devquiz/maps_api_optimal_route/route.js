//
// route.js
// Kosei Moriyama <cou929@gmail.com>
//
// Answer for Maps API problem of Google Developers Day 2010 DevQuiz.
// 

(function() {
   var inputs = [
     [
       ["名古屋城", 35.185590, 136.899060],
       ["五条大橋", 34.995682, 135.767890],
       ["京都リサーチパーク", 34.994707, 135.740076]
     ],
     [
       ["東京タワー", 35.658570, 139.745484],
       ["清水寺", 34.994835, 135.784953],
       ["名古屋城", 35.185590, 136.899060],
       ["青葉城跡", 38.251127, 140.855294],
       ["法隆寺", 34.614756, 135.734254],
       ["日本銀行", 35.686839, 139.771438]
     ],
     [
       ["首里城", 26.216991, 127.719362],
       ["熊本城", 32.804722, 130.707835],
       ["坂本竜馬記念館", 33.496428, 133.571845],
       ["春日大社", 34.681480, 135.848313],
       ["宗谷岬", 45.522744, 141.936603],
       ["国会正門前", 35.676293, 139.746927],
       ["秋吉台", 34.234753, 131.310094],
       ["原爆ドーム", 34.395477, 132.453620],
       ["東京ビッグサイト", 35.629898, 139.794127],
       ["京都リサーチパーク", 34.994707, 135.740076]
     ]
   ];

   var request_url = 'http://maps.google.com/maps/api/directions/json?sensor=false';
   var graph = [];
   var visited = {};
   var best = Infinity;
   var best_path = null;

   function solve(input) {
     graph = [];
     visited = {};
     best = Infinity;
     best_path = null;
     var ret = "";
     
     // construct graph
     for (var i=0, origin; origin=input[i]; i++) {
       var tmp = [];
       for (var j=0, destination; destination=input[j]; j++) {
         if (i == j)
           tmp.push(Infinity);
         else
           tmp.push(getDuration(origin, destination));
         sleep(1000);
       }
       graph.push(tmp);
     }

     // search graph
     visited[0] = true;
     traverse([0], 0);

     // make result
     var n = best_path.length;
     for (i=0; i<n; i++)
       ret += input[best_path[i]][0] + " ";
     ret += input[0][0];

     return ret;
   }

   // search graph by dfs
   function traverse(path, cost) {
     var cur = path[path.length-1];
     if (path.length === graph.length) {
       if (cost + graph[cur][0] < best) {
         best = cost + graph[cur][0];
         best_path = path.slice();
       }
       return;
     }

     visited[cur] = true;

     var n = graph.length;
     for (var i=0; i<n; i++)
       if (!visited[i] && graph[cur][i] !== Infinity) {
         path.push(i);
         traverse(path, cost + graph[cur][i]);
         path.pop();
       }

     visited[cur] = null;
     return;
   }

   // get duration using google map api
   function getDuration(ori, dst) {
     var ret = null;
     var url = request_url + 
       '&origin=' + ori[1] + ',' + ori[2] +
       '&destination=' + dst[1] + ',' + dst[2];

     var xhr = new XMLHttpRequest();
     xhr.open('GET', url, false);
     xhr.send();
     if (xhr.readyState == 4 && xhr.status == 200) {
       var res = JSON.parse(xhr.responseText);
       ret = res.routes[0].legs[0].duration.value;
     }

     return ret;
   }

   function sleep(milliSeconds) {
     var startTime = new Date().getTime();
     while (new Date().getTime() < startTime + milliSeconds)
       ;
   }

   // solve each problem
   console.log(solve(inputs[0]));
   console.log(solve(inputs[1]));
   console.log(solve(inputs[2]));
 })();

// 1 名古屋城 五条大橋 京都リサーチパーク 名古屋城
// 2 東京タワー 日本銀行 青葉城跡 清水寺 法隆寺 名古屋城 東京タワー
// 3 首里城 熊本城 秋吉台 坂本竜馬記念館 春日大社 東京ビッグサイト 国会正門前 宗谷岬 京都リサーチパーク 原爆ドーム 首里城
