using System.Text.Json.Serialization;

namespace MonitoramentoWebApi;
// Classe que representa os dados do Pico
public class PicoData
{
    // Representa o valor da temperatura
    [JsonPropertyName("temperature")]
    public float Temperature { get; set; }

    // Representa o estado do botão A
    [JsonPropertyName("btn_a_state")]
    public uint ButtonAState { get; set;}

    // Representa o estado do botão B
    [JsonPropertyName("btn_b_state")]
    public uint ButtonBState { get; set; }

    // Construtor padrão
    public PicoData() { }

    // Construtor com parâmetros
    public PicoData(float temperature, uint buttonAState, uint buttonBState)
    {
        Temperature = temperature;
        ButtonAState = buttonAState;
        ButtonBState = buttonBState;
    }
}
