# Monitoramento de Botões via Web

Este projeto monitora dois botões e a temperatura interna da Raspberry Pi Pico W, enviando os dados a um servidor web para visualização em tempo real.

🔗 Servidor remoto: [monitoramento-botoes-web](https://monitoramento-botoes-web-production.up.railway.app/)

## 📁 Estrutura

- **Firmware (C)**: Lê os botões (GPIO 5 e 6) e o sensor de temperatura, enviando dados via HTTP.
- **Servidor Web (ASP.NET Core)**: API REST com interface web para exibição dos dados.

## ⚙️ Requisitos

### Pico W

- Raspberry Pi Pico W
- 2 botões (GPIO 5 e 6)
- Pico SDK, GCC, CMake, Ninja

### Web Server

- .NET SDK 6.0+
- Navegador moderno

## 🚀 Execução

### 🔧 Execução Local

1. **Servidor:**
   ```bash
   cd src/web-server/MonitoramentoWebApi
   dotnet restore
   dotnet run
   ```
2. **Pico W:** configure wifi_connection.h com sua rede:

   ```c
   #define WIFI_SSID "SEU_SSID"
   #define WIFI_PASSWORD "SUA_SENHA"
   ```

   Configure o IP local no firmware:

   ```c
   #define SERVER_IP "192.168.X.X" // IP do seu PC local
   ```

3. Compile e envie o firmware para a Pico.

## 🌐 Execução Remota com Proxy

1. **Servidor Proxy**: execute o projeto proxy-server:
   ```bash
   cd src/proxy-server
   node proxy-server.js
   ```
2. **Pico W**: configure SERVER_IP com IP do seu PC que está rodando o proxy.

3. O proxy encaminhará os dados para o servidor remoto hospedado (Railway).

## 🔄 Funcionamento

1. Pico W lê botões e temperatura.

2. Envia via HTTP POST para o servidor.

3. A interface web exibe os dados em tempo real.

## 🗂️ Principais Arquivos

### Firmware

- monitoramento-botoes-web.c

- wifi_connection.[h/c]

- button_monitor.[h/c]

- temperature_sensor.[h/c]

- web_server.[h/c]

### Web Server

- Program.cs

- PicoData.cs

- wwwroot/index.html, script.js, styles.css
