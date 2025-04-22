# Projeto de Monitoramento de Botões WEB

Este projeto consiste em um sistema de monitoramento de botões e temperatura utilizando um microcontrolador Raspberry Pi Pico W. Os dados coletados pelos sensores são enviados para um servidor web, onde podem ser visualizados em tempo real por meio de uma interface web.

## Estrutura do Projeto

O projeto é dividido em duas partes principais:

1. **Firmware do Raspberry Pi Pico W**:

   - Código em C que coleta os dados dos sensores (botões e temperatura) e os envia para o servidor web via HTTP.
   - Principais funcionalidades:
     - Monitoramento do estado de dois botões.
     - Leitura da temperatura utilizando o sensor interno do Raspberry Pi Pico W.
     - Envio dos dados para o servidor web.

2. **Servidor Web**:
   - Aplicação ASP.NET Core que recebe os dados enviados pelo Raspberry Pi Pico W e os disponibiliza para visualização em uma interface web.
   - Principais funcionalidades:
     - API REST para receber e fornecer os dados dos sensores.
     - Interface web para exibir os dados em tempo real.

## Requisitos para Execução

### Firmware do Raspberry Pi Pico W

1. **Hardware**:

   - Raspberry Pi Pico W.
   - Dois botões conectados aos pinos GPIO 5 e GPIO 6.
   - Rede Wi-Fi disponível para conexão.

2. **Software**:

   - [Pico SDK](https://github.com/raspberrypi/pico-sdk) configurado no ambiente de desenvolvimento.
   - Compilador ARM GCC.
   - Ferramentas de build como CMake e Ninja.

3. **Configuração**:

   - Configure o arquivo `wifi_connection.h` com o SSID e a senha da sua rede Wi-Fi:
     ```c
     #define WIFI_SSID "SEU_SSID"
     #define WIFI_PASSWORD "SUA_SENHA"
     ```

4. **Compilação e Upload**:
   - Compile o firmware utilizando o CMake e Ninja:
     ```bash
     mkdir build
     cd build
     cmake ..
     ninja
     ```
   - Faça o upload do firmware para o Raspberry Pi Pico W utilizando o `picotool` ou outra ferramenta de sua preferência.

---

### Servidor Web

1. **Requisitos de Software**:

   - .NET SDK 9.0 ou superior.
   - Ambiente de desenvolvimento configurado para ASP.NET Core.

2. **Configuração**:

   - Certifique-se de que o servidor está configurado para rodar na porta `5000` (ou ajuste conforme necessário no arquivo ).

3. **Execução**:

   - Navegue até o diretório do servidor web:
     ```bash
     cd src/web-server/MonitoramentoWebApi
     ```
   - Restaure as dependências e execute o servidor:
     ```bash
     dotnet restore
     dotnet run
     ```

4. **Acesso à Interface Web**:
   - Abra um navegador e acesse `http://<IP_DO_SERVIDOR>:5000` para visualizar os dados em tempo real.

---

## Funcionamento

1. O Raspberry Pi Pico W coleta os dados dos botões e do sensor de temperatura.
2. Os dados são enviados via HTTP POST para o servidor web.
3. O servidor web armazena os dados e os disponibiliza para a interface web.
4. A interface web exibe os dados atualizados em tempo real.

---

## Estrutura de Arquivos

- **Firmware**:
  - : Código-fonte do firmware para o Raspberry Pi Pico W.
- **Servidor Web**:
  - : Código-fonte do servidor web em ASP.NET Core.
- **Interface Web**:
  - `wwwroot/`: Arquivos HTML, CSS e JavaScript para a interface web.

---

## Observações

- Certifique-se de que o Raspberry Pi Pico W e o servidor web estão conectados à mesma rede para que a comunicação funcione corretamente.
- O endereço IP do servidor deve ser configurado no firmware do Raspberry Pi Pico W no arquivo :
  ```c
  #define SERVER_IP "192.168.1.196" // Substitua pelo IP do servidor
  ```
