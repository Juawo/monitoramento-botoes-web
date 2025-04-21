using Microsoft.AspNetCore.Http.HttpResults;
using MonitoramentoWebApi;

var builder = WebApplication.CreateBuilder(args);

var app = builder.Build();

app.UseStaticFiles();

PicoData? data = null;

app.MapGet("/dados", () =>
{
    if (data != null)
    {
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

app.MapFallbackToFile("wwwroot/index.html");

app.Run();
