words = [
"ajnghpjk","kcqimtfxs","kmzfvq","kjqattuor","slmilghoq","sypqxxmzvgr","soqiey","qzebr","qctwyihy","qfefta","rcgllxfy","rhqla","remejlgee","ywczhdswa","yfeisve","yyzhx","avkvvve","azjmurhsyrx","aertbhsnou","eqlhmrwkx","eqrjqvu","eperk","xpbcbqu","xeoszilk","xbuxs","uykhdhrjvk","ufytbmbkjs","ulakdyq","kyyrxufmun","nuolvnpcg","nxcbmwmugj","nscctrprpl","sqnni","ixuauo","infiqgb","inndmebup","qiftdm","mqduvncctff","myeerlv","mdlffijw","rxmsdkzn","yvcbji","abqdgzm","epwhkn","xnefdtsyi","unbkm","gybaualmtdo","glsqf","gjhlyguj","gwsrxgwqb","gglmdjgaxv","gopwcfbyel","gmtap","gtylw","gvsbyqjt","ghtgpd","gmlgmjlpyc","ovjhyg","obaardcslif","opfuj","oecffb","oqcdtgxmv","oultznl","opslsp","ovhcijvefw","oiqqjamnoft","orthped","oocldc","ftraryg","fzdgszxlo","fnfgj","fpcziyb","fbmsv","fbaolursl","fhqbmfiqdp","fufiwithtw","fgsdotwwt","flugtwdd","fftixgc","jlghsdxkg","jxfgho","jhxytblyf","jujacfeelqb","jgnqthhv","jugupvil","jbcgweipdvp","jzjew","jolat","jaegejdd","joswzc","biprkjczxkg","bhfuo","bndhtwpupf","befbmyedj","brmmcv","blkwortntl","brdtwgmp","bdynnhakkow","bbujt","bjpdd","bdkditc","vcjnedug","vbasjrso","voovypjf","vxqixyj","vznasb","vvzbnfyqskl","vlilgjmp","vjauew","vejtrhicwht","vbbsswnshd","vdvqdfnc","lvfug","lglyjvlo","lfhwyxpnqvf","lvkmtuzej","lajub","ldgfv","lfzthkmp","lognzytdw","lahugtilmt","lmvewwvdd","lagtnijc","prluoqmyeg","pkhvoynicbo","pqgkhkidrf","pmbfnj","paaujzvob","pwfwtv","pbrhdol","ptakyw","pmvtfjkumt","pzgjzd","plvqc","wnakyneyg","wzlymoeoko","wqnpvvaf","wsivgj","wvxkotlnbub","wubgfv","wkdjrcyqgdl","wwbmbnphp","wmcknt","wjwwnhd","wvvnaupc","tjeioanlgg","tczpfo","tsjhemif","tqsgkj","tteib","tzichtdypcv","tdrljvl","tkatfwmqp","tbdoihozw","tdrxtsgd","tjxybxxc","dzjsqpbg","dwainnqxlwo","dkemhuuguf","dwyervfbej","dlkdsvoqb","dhbncblv","deunjbl","dcwpp","dicdpzw","dcxit","dpdjjc","cnhtg","ccrto","chzhdif","cmkqyqgej","crtdnwb","clbkcfv","cwdgosrl","cyicelykp","ckzvww","cqtqteiseit","cxjigyind","tnmpsk","tmehlr","tdapje","dcufljlks","drqogvxhy","dxgyix","ccreofpnq","cojntfnuhra","crclfhu"
 ]

#    "kavhhchrpsx","xwgqlxrgqd","xbgfdf","xumcia","xmwwrw","dagnrelf","ddhlhameia","ftconhsq","fldfgtesvqs","fsvwpcbeusw","fbdqj","qjhhguxcvss","qgpeoevnv","qzcdqtngev","swcrftjbje","spnng","slrypmjn","eknlrg","edcfjsekypp","gosnhrh","ghfcmc","gsggexvr","hukeknbglc","hbxnscji","hiqkcwyi","hzqsbl","cdehyt","chdgginl","txcadswnvk","arhieourqy","yebpxkskiv","vvesfxtluo","oeomp","pmxdvyuhu","pbegsbxjn","uajwzmrvbh","ugwuqihi","itivmz","zphenizdem","mrrqkjb","wiqdanvqj","jkhoedlv","nimlsdmbml","llzcr", "rbqgvfk", "kpmykriejqb"

#     "fzkhd",    "delpmdiaepu",    "ncfocyhkrd",    "fsegxypjn",    "ovwhof",    "zlizyclo",    "wfpvuezgz",    "ucirdtdaiww",    "dzbkndo",    "njrskolafcz",    "fhmmagw",    "ootwhmxtju",    "zshpd",    "wxfdqooin",    "uktuff",    "dufzaqcqz",    "nymfdcayww",    "fremsyku",    "ondtimyred",    "zlxqqerayun",    "wcwnmsf",    "uefxxwhrkfo"



print '''<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html>
    
    <head>
        <title>Cytoscape Web example</title>
        
        <script type="text/javascript" src="js/min/json2.min.js"></script>
        <script type="text/javascript" src="js/min/AC_OETags.min.js"></script>
        <script type="text/javascript" src="js/min/cytoscapeweb.min.js"></script>
        
        <script type="text/javascript">
            window.onload = function() {
                // id of Cytoscape Web container div
                var div_id = "cytoscapeweb";
                
                // NOTE the attributes on nodes and edges
                var xml = '\\
                <graphml>\\
                  <key id="label" for="all" attr.name="label" attr.type="string"/>\\
                  <key id="foo" for="node" attr.name="foo" attr.type="string"/>\\
                  <key id="bar" for="edge" attr.name="bar" attr.type="string"/>\\
                  <graph edgedefault="directed">\\
''',

id = 1
for w in words:
    print '                    <node id="' + str(id) + '"><data key="label">' + w + '</data></node>\\'
    id += 1

# <edge target="1" source="2"></edge>
visited = [False] * len(words)
visited[0] = True
gindex = 1

print '                    <node id="' + str(gindex) + '"><data key="label">' + words[0] + '</data></node>\\'
gindex += 1

badid = 10000000

def trv(cur, gcur, turn):
    global gindex
    global badid
    global visited
    last_char = words[cur][-1]
    next = []
    
    for i in range(len(words)):
        if last_char == words[i][0] and not visited[i]:
            next.append(i)

#    if len(next) == 0 and turn % 2 == 0:
    if turn == 3:
        print '                    <node id="' + str(badid) + '"><data key="label">GOAL</data></node>\\'
        print '                    <edge target="' + str(badid) + '" source="' + str(gcur) + '"></edge>\\'
        badid += 1
        return

    for i in next:
        print '                    <node id="' + str(gindex) + '">' + words[cur] + '</node>\\'
        gindex += 1
        print '                    <edge target="' + str(gindex-1) + '" source="' + str(gcur) + '"></edge>\\'
        visited[i] = True
        trv(i, gindex-1, turn + 1)
        visited[i] = False

trv(0, 1, 0)

path = []
lookup = {}
def trv2(cur, turn):
    global path
    last_char = words[cur][-1]
    next = []
    
    for i in range(len(words)):
        if last_char == words[i][0] and not visited[i]:
            next.append(i)

    if len(next) == 2:
        if turn % 2 == 1:
            print path
            return
        else:
            return

    for i in next:
        visited[i] = True
        path.append(words[i])
        trv2(i, turn + 1)
        visited[i] = False
        path.pop()

#     if len(next) == 0:
#         if turn % 2 == 1:
#             lookup[str(path)] = True
#             return True
#         else:
#             lookup[str(path)] = False
#             return False

#     res = False
#     if len(next) > 0:
#         if turn % 2 == 0:
#             res = False
#             for i in next:
#                 visited[i] = True
#                 path.append(words[i])
#                 res |= trv2(i, turn + 1)
#                 visited[i] = False
#                 path.pop()
#                 if res:
#                     break
#         else:
#             res = True
#             for i in next:
#                 visited[i] = True
#                 path.append(words[i])
#                 res &= trv2(i, turn + 1)
#                 visited[i] = False
#                 path.pop()
#                 if not res:
#                     break

#     lookup[str(path)] = res
    
#    return res

# path.append(words[0])
# path.append(words[1])
# path.append(words[4])
# path.append(words[9])
# path.append(words[16]) # avkvvve
# path.append(words[20]) # eqriqvu
# path.append(words[25]) # ufytbmbkjs
# visited[0] = True
# visited[1] = True
# visited[4] = True
# visited[9] = True
# visited[16] = True
# visited[20] = True
# visited[25] = True

# trv2(25, 0)

# while True:
#     key = raw_input()
#     if lookup[str(key.split(','))]:
#         print 'ok'
#     else:
#         print 'ng'

print '''                  </graph>\\
                </graphml>\\
                ';
                
                // initialization options
                var options = {
                    swfPath: "swf/CytoscapeWeb",
                    flashInstallerPath: "swf/playerProductInstall"
                };
                
                var vis = new org.cytoscapeweb.Visualization(div_id, options);
               
                // callback when Cytoscape Web has finished drawing
                vis.ready(function() {
                
                    // add a listener for when nodes and edges are clicked
                    vis.addListener("click", "nodes", function(event) {
                        handle_click(event);
                    })
                    .addListener("click", "edges", function(event) {
                        handle_click(event);
                    });
                    
                    function handle_click(event) {
                         var target = event.target;
                         
                         clear();
                         print("event.group = " + event.group);
                         for (var i in target.data) {
                            var variable_name = i;
                            var variable_value = target.data[i];
                            print( "event.target.data." + variable_name + " = " + variable_value );
                         }
                    }
                    
                    function clear() {
                        document.getElementById("note").innerHTML = "";
                    }
                
                    function print(msg) {
                        document.getElementById("note").innerHTML += "<p>" + msg + "</p>";
                    }
                });

                // draw options
                var draw_options = {
                    // your data goes here
                    network: xml,
                    // hide pan zoom
                    panZoomControlVisible: true,
                    layout: 'Tree'
                };
                
                vis.draw(draw_options);
            };
        </script>
        
        <style>
            * { margin: 0; padding: 0; font-family: Helvetica, Arial, Verdana, sans-serif; }
            html, body { height: 100%; width: 100%; padding: 0; margin: 0; }
            body { line-height: 1.5; color: #000000; font-size: 14px; }
            /* The Cytoscape Web container must have its dimensions set. */
            #cytoscapeweb { width: 3000px; height: 3000px; }
            #note { width: 100%; height: 50%; background-color: #f0f0f0; overflow: auto;  }
            p { padding: 0 0.5em; margin: 0; }
            p:first-child { padding-top: 0.5em; }
        </style>
    </head>
    
    <body>
        <div id="cytoscapeweb">
            Cytoscape Web will replace the contents of this div with your graph.
        </div>
    </body>
    
</html>
'''










#"kavhhchrpsx","xwgqlxrgqd","xbgfdf","xumcia","xmwwrw","dagnrelf","ddhlhameia","ftconhsq","fldfgtesvqs","fsvwpcbeusw","fbdqj","qjhhguxcvss","qgpeoevnv","qzcdqtngev","swcrftjbje","spnng","slrypmjn","eknlrg","edcfjsekypp","gosnhrh","ghfcmc","gsggexvr","hukeknbglc","hbxnscji","hiqkcwyi","hzqsbl","cdehyt","chdgginl","txcadswnvk","arhieourqy","yebpxkskiv","vvesfxtluo","oeomp","pmxdvyuhu","pbegsbxjn","uajwzmrvbh","ugwuqihi","itivmz","zphenizdem","mrrqkjb","wiqdanvqj","jkhoedlv","nimlsdmbml","llzcr", "rbqgvfk", "kpmykriejqb"



