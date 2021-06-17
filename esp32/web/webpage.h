String webpageCode = R"***(
<!DOCTYPE html>
<html>
<head>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <div id="chart_div"></div>
    <script>
        google.charts.load('current', { packages: ['corechart', 'line'] });

        const msRefreshTime = 5000;
        var timeCount = 0;
        var chart;
        var data;
        var maxTemp = 0;
        var options = {
                hAxis: {
                    title: 'Time (sec)'
                },
                vAxis: {
                    title: 'Temperature Degrees (C)',
                    viewWindow:{
                      min:0
                    }
                },
                series: {
                    1: { curveType: 'function' }
                }
            };

        google.charts.setOnLoadCallback(drawCurveTypes);
        
        function drawCurveTypes() {
            data = new google.visualization.DataTable();
            data.addColumn('number', 'X');
            data.addColumn('number', 'Temp');
            chart = new google.visualization.LineChart(document.getElementById('chart_div'));
            chart.draw(data, options);
        }


        setInterval(function () {
            getPOTValue();
        }, msRefreshTime);

        function getPOTValue() {
            
            var POTvalRequest = new XMLHttpRequest();
            POTvalRequest.onreadystatechange = function()
            {
                if (this.readyState == 4 && this.status == 200)
                {
                  var temp = parseFloat(this.responseText)
                  if (temp > maxTemp)
                  {
                      maxTemp = temp;
                      document.getElementById("MaxTemp").innerHTML = maxTemp.toFixed(2);
                  }
                  data.addRows([[timeCount / 1000, temp]]);
                  chart.draw(data, options);
                  timeCount += msRefreshTime
                }
            };
            POTvalRequest.open("GET","readTEMP",true);
            POTvalRequest.send();
            
        }


    </script>
</head>

<body>
    <div>
        <h2>Max temp: <span id="MaxTemp">0</span>
        </h2>
    </div>
</body>
</html>

)***";
