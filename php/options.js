
      var globalOptions = {
        global: {
          useUTC: false
        }
      }
      
      var options1 = {
      
              chart: {
                  type: 'areaspline',
                  renderTo: "canvas",
                  zoomType: "x",
                  spacingLeft: 5,
                  spacingRight: 5,
                  //borderColor: '#000000',
                  borderWidth: 1,
                  events: {
                      
                  }
              },
              legend: {
                  enabled: true,
                  floating: true,
                  align: 'center',
                  verticalAlign: 'top',
                 // y: 30
              },
              navigator: {
                  margin: 10
              },
              rangeSelector: {
                  inputEnabled: false,
                  buttons: [{
                    type: 'minute',
                    count: 180,
                    text: '3h'
                  }, {
                    type: 'day',
                    count: 1,
                    text: '1d'
                  }, {
                    type: 'day',
                    count: 3,
                    text: '3d'
                  }, {
                    type: 'week',
                    count: 1,
                    text: '1w'
                  }, {
                    type: 'all',
                    text: 'All'
                  }],
                  selected: 0
              },

              scrollbar: {
                enabled: false
              },
       
              xAxis: {
                 //startOnTick: true,
                 //endOnTick: true,
                  //showFirstLabel: true,
                  //showLastLabel: true,
                  gridLineWidth: 1,
                  ordinal: false,
                  //min: Date.UTC(start.getUTCFullYear(), start.getUTCMonth(), start.getUTCDate(), 0,0,0,0),
                  //max: Date.UTC(start.getUTCFullYear(), start.getUTCMonth(), start.getUTCDate(), 23,59,59,999),
                  //range:  48 * 3600 * 1000,
                  //minRange: 300000

              },

              yAxis:[{
                    gridLineWidth: 1,
                    offset: 15,
                    showEmpty: false,
                    plotLines: [{
                      color: 'red', // Color value
                      value: '0', // Value of where the line will appear
                      width: '2' // Width of the line    
                    }]
              },{
                    offset: 0,
                    opposite: false,
                    showEmpty: false,  
                    allowDecimals: false 
              },{
                    offset: 30,
                    showEmpty: false,
                    allowDecimals: false     
              }],

              tooltip: {
                  valueDecimals: 2
               
              },
                                             
              series: [{
                  yAxis: 0,
                  name: 'Teplota',
                  data: []
              },{
                  yAxis: 1,
                  name: "Tlak",
                  type: "spline",
                  data: []
              },{
                  yAxis: 2,
                  name: "Vlhkost",
                  type: "area",
                  data: []
              }]

        };

        var options2 = {
          chart: {
                type: 'columnrange',
                renderTo: "canvas2",
                zoomType: "x",
                height: 300
            },

            rangeSelector: {
                selected: 2
            },

            scrollbar: {
                enabled: false
            },

            tooltip: {
                valueSuffix: '°C'
            },
            
            legend: {
                  enabled: true,
                  floating: true,
                  align: 'center',
                  verticalAlign: 'top',
                 // y: 30
            },

            navigator: {
                  margin: 10,
                  height: 25
            },

            xAxis:{
              ordinal: false,
              minRange: 1000 * 3600 * 24 * 7,
              minTickInterval: 1000 * 3600 * 24
            },

            yAxis:[{
              gridLineWidth: 1,
              offset: 15,
              showEmpty: false
            },{
              opposite: false,
              offset: 15,
              showEmpty: false
            }],

            series: [{
              yAxis: 0,
              name: 'Teplota',
              data: []
            },{
              yAxis: 1,
              name: "Tlak",
              type: "spline",
              data: []
            }]

        };