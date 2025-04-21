namespace MonitoramentoWebApi;
public class PicoData
{
    public float Temperature { get; set; }
    public bool ButtonAState { get; set; }
    public bool ButtonBState { get; set; }

    public PicoData(float temperature, bool buttonAState, bool buttonBState)
    {
        Temperature = temperature;
        ButtonAState = buttonAState;
        ButtonBState = buttonBState;
    }

    
}
