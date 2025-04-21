async function atualizarDados() {
    try {
        const response = await fetch('/dados');
        const json = await response.json();

        document.getElementById('temp').textContent = json.Temperature.toFixed(2);
        document.getElementById('btnA').textContent = json.ButtonAState ? "Pressionado" : "Solto";
        document.getElementById('btnB').textContent = json.ButtonBState ? "Pressionado" : "Solto";
    } catch (e) {
        console.error("Erro ao buscar dados : ", e);
    }
}

setInterval(atualizarDados, 1000);
atualizarDados();