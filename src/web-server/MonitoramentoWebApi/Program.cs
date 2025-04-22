using System.Net;
using Microsoft.AspNetCore.Http.HttpResults;
using MonitoramentoWebApi;

var builder = WebApplication.CreateBuilder(args);
builder.WebHost.UseUrls("http://0.0.0.0:5000");

var app = builder.Build();

PicoData? data = new (2.0f, 0, 1);

app.UseDefaultFiles();
app.UseStaticFiles();

app.MapGet("/dados", () =>
{
    if (data != null)
    {
        // Console.WriteLine(data);
        return Results.Json(data);
    }
    return Results.Json(new { Temperature = 0.0f, ButtonAState = false, ButtonBState = false });
});

app.MapPost("/dados", async (HttpContext context) =>
{
    var body = await context.Request.ReadFromJsonAsync<PicoData>();
    if (body != null)
    {
        data = body;
        Console.WriteLine($"Dados Recebidos da Pico W: Temp={body.Temperature} A={body.ButtonAState} B={body.ButtonBState}");
        return Results.Ok("Dados Recebidos");
    }
    return Results.BadRequest("JSON inválido!");
});

// app.MapFallbackToFile("wwwroot/index.html");

var localIp = GetLocalIpAdress();
Console.WriteLine($"Servidor rodando em : http://{localIp}:5000");

app.Run();

static string GetLocalIpAdress()
{
    var host = Dns.GetHostEntry(Dns.GetHostName());
    foreach (var ip in host.AddressList)
    {
        if (ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork)
        {
            return ip.ToString();
        }
    }
    return "localhost";
}
