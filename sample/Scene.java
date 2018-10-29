package sample;

import javafx.scene.chart.XYChart;

import java.util.ArrayList;
import java.util.List;

import static java.lang.Math.*;

public class Scene {

    private double x0;
    private double y0;
    private double X;
    private int N;

    public Scene(double x0, double y0, double X, int N) {
        this.x0 = x0;
        this.y0 = y0;
        this.X = X;
        this.N = N;
    }


    public List<XYChart.Series> getSolutions(boolean exact, boolean euler, boolean ie, boolean rk) {
        List<XYChart.Series> result = new ArrayList<>(4);
        double h = (X - x0) / N;
        Double x[] = new Double[N + 1];
        x[0] = x0;
        for (int i = 1; i <= N; i++) {
            x[i] = x[i - 1] + h;
        }
        Double y[] = new Double[N + 1];
        y[0] = y0;
        if (exact) {
            result.add(exact(x, y, N));
        } else
            result.add(null);
        if (euler) {
            result.add(euler(x, y, h, N));
        } else
            result.add(null);
        if (ie) {
            result.add(ie(x, y, h, N));
        } else
            result.add(null);
        if (rk) {
            result.add(rk(x, y, h, N));
        } else
            result.add(null);
        return result;
    }

    private XYChart.Series<Number, Number> exact(Double x[], Double y[], int N) {
        Double c = findC();
        for (int i = 1; i <= N; i++) {
            y[i] = (exp(x[i] + c) - 1 ) * (exp(x[i] + c) - 1 );
        }
        return doublesToSeries(x, y, "Exact");
    }
    private Double findC() {
        return log(sqrt(y0) + 1) - x0;
    }

    private XYChart.Series<Number, Number> euler(Double x[], Double y[], double h, int N) {
        for (int i = 1; i <= N; i++) {
            y[i] = y[i - 1] + h * (f(x[i - 1], y[i - 1]));
        }
        return doublesToSeries(x, y, "Euler");
    }

    private XYChart.Series<Number, Number> ie(Double x[], Double y[], double h, int N) {
        for (int i = 1; i <= N; i++) {
            y[i] = y[i - 1] + h * (f(x[i - 1] + h / 2, y[i - 1] + h * f(x[i - 1], y[i - 1]) / 2));
        }
        return doublesToSeries(x, y, "Improved Euler");
    }

    private XYChart.Series rk(Double x[], Double y[], double h, int N) {
        for (int i = 1; i <= N; i++) {
            double k1 = f(x[i - 1], y[i - 1]);
            double k2 = f(x[i - 1] + h / 2, y[i - 1] + h * k1 / 2);
            double k3 = f(x[i - 1] + h / 2, y[i - 1] + h * k2 / 2);
            double k4 = f(x[i - 1] + h, y[i - 1] + h * k3);
            y[i] = y[i - 1] + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        }
        return doublesToSeries(x, y, "Runge-Kutta");
    }

    private Double f(Double x, Double y) {
        return (2*Math.pow(y,1/2) + 2 * y);
    }

    // Create XYChart.Series from 2 arrays of double and set name to plot
    private XYChart.Series<Number, Number> doublesToSeries(Double x[], Double y[], String name) {
        XYChart.Series result = new XYChart.Series();
        result.setName(name);
        for (int i = 0; i < x.length; i++) {
            result.getData().add(new XYChart.Data(x[i], y[i]));
        }
        return result;
    }

    // Return the list of all required truncation error of solution Series
    public List<XYChart.Series> getTrunc(boolean euler, boolean ie, boolean rk, int n0, int ni) {
        List<XYChart.Series> result = initializeGetTruncRez(euler, ie, rk);
        for (int n = n0; n <= ni; n++) {
            N = n;
            List<XYChart.Series> seriesList = getSolutions(true, euler, ie, rk);
            for (int method = 1; method < 4; method++) {
                if (seriesList.get(method) != null) {
                    result.get(method - 1).getData().add(new XYChart.Data(n, getMaxTrunc(seriesList.get(0), seriesList.get(method))));
                }
            }
        }
        return result;
    }

    // Initialize list of Series and Series elements. Elements which are not chosen are null
    private List<XYChart.Series> initializeGetTruncRez(boolean euler, boolean ie, boolean rk) {
        List<XYChart.Series> result = new ArrayList<XYChart.Series>(3);
        if (euler) {
            result.add(new XYChart.Series());
            result.get(0).setName("euler");
        } else
            result.add(null);
        if (ie) {
            result.add(new XYChart.Series());
            result.get(1).setName("ie");
        } else
            result.add(null);
        if (rk) {
            result.add(new XYChart.Series());
            result.get(2).setName("rk");
        } else
            result.add(null);
        return result;
    }

    // Return maximum value of difference between exact solution and numerical
    private double getMaxTrunc(XYChart.Series exact, XYChart.Series series) {
        double trunc = 0;
        for (int i = 0; i <= N; i++) {
            XYChart.Data<Number, Number> currentExact = (XYChart.Data) exact.getData().get(i);
            XYChart.Data<Number, Number> currentSeries = (XYChart.Data) series.getData().get(i);
            trunc = trunc + (double) currentExact.getYValue() - (double) currentSeries.getYValue();

        }
        return trunc;
    }
}

