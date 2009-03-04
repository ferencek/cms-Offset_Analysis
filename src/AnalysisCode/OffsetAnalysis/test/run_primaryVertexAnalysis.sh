echo ">> `date +'%b %d %Y %T %Z'` Starting PV analysis on $HOST"

echo ">> `date +'%b %d %Y %T %Z'` Running: ./primaryVertexAnalysis.sh offlinePrimaryVertices"
./primaryVertexAnalysis.sh offlinePrimaryVertices

# echo ">> `date +'%b %d %Y %T %Z'` Running: ./primaryVertexAnalysis.sh offlinePrimaryVerticesWithBS"
# ./primaryVertexAnalysis.sh offlinePrimaryVerticesWithBS
# 
# echo ">> `date +'%b %d %Y %T %Z'` Running: ./primaryVertexAnalysis.sh pixelVertices"
# ./primaryVertexAnalysis.sh pixelVertices

echo ">> `date +'%b %d %Y %T %Z'` PV analysis completed!"