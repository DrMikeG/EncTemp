String webpageCode = R"**"


<body>
<div>
    <h2>POT Value : <span id="POTValue">0</span>
    </h2>
</div>
    <script>
    setInterval(function()
    {
        getPOTValue();
    },2000);

    function getPOTValue()
    {
        var POTvalRequest = new XMLHttpRequest();
        POTvalRequest.onreadystatechange = function()
        {
            if (this.readyState == 4) && this.status == 200)
            {
                document.getElementById("POTValue").innerHTML = this.responseText;
            }
        };
        POTvalRequest.open("GET","readPOT",true);
        POTvalRequest.send();
    }
    
    </script>
</body>
