using System.Text.Json.Serialization;

namespace MonitoramentoWebApi;
public class PicoData
{
    [JsonPropertyName("temperature")]
    public float Temperature { get; set; }

    [JsonPropertyName("btn_a_state")]
    public uint ButtonAState { get; set;}

    [JsonPropertyName("btn_b_state")]
    public uint ButtonBState { get; set; }

    public PicoData() { }
    public PicoData(float temperature, uint buttonAState, uint buttonBState)
    {
        Temperature = temperature;
        ButtonAState = buttonAState;
        ButtonBState = buttonBState;
    }

}
