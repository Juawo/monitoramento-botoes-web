using System.Net;
using MonitoramentoWebApi; 

// Cria o builder para configurar o aplicativo.
var builder = WebApplication.CreateBuilder(args); 
// Define a URL base do servidor.
var port = Environment.GetEnvironmentVariable("PORT") ?? "8080";
builder.WebHost.UseUrls($"http://0.0.0.0:{port}");

// Constrói o aplicativo.
var app = builder.Build(); 

// Inicializa um objeto de dados com valores padrão.
PicoData? data = new (2.0f, 0, 1); 

// Habilita arquivos padrão como index.html.
app.UseDefaultFiles(); 
// Habilita o uso de arquivos estáticos.
app.UseStaticFiles(); 

// Define endpoint GET para retornar os dados.
app.MapGet("/dados", () => 
{
    // Verifica se os dados existem.
    if (data != null) 
    {
        // Retorna os dados como JSON.
        return Results.Json(data); 
    }
    // Retorna valores padrão.
    return Results.Json(new { Temperature = 0.0f, ButtonAState = false, ButtonBState = false }); 
});

// Define endpoint POST para receber dados.
app.MapPost("/dados", async (HttpContext context) => 
{
    // Lê o corpo da requisição como JSON.
    var body = await context.Request.ReadFromJsonAsync<PicoData>(); 
    // Verifica se os dados são válidos.
    if (body != null) 
    {
        // Atualiza os dados recebidos.
        data = body; 
        // Loga os dados recebidos.
        Console.WriteLine($"Dados Recebidos da Pico W: Temp={body.Temperature} A={body.ButtonAState} B={body.ButtonBState}"); 
        // Retorna sucesso.
        return Results.Ok("Dados Recebidos"); 
    }
    // Retorna erro se o JSON for inválido.
    return Results.BadRequest("JSON inválido!"); 
});

app.Run(); 
