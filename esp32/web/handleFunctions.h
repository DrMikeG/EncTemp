// Handle functions executed upon client request 
void handleRoot() 
{
    server.send(200, "test/html", webpageCode);
}

void handlePOT()
{
    String POTval = String(analogRead(A0));
    server.send(200,"text/plane", POTval);
}
